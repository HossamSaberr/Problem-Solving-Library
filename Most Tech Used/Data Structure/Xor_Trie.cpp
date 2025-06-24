template <int LOG = 60>
class Binary_trie {
private:
    struct node {
        int cnt = 0, child[2] = {-1, -1};
    };
 
public:
    vector<node> tree;
 
    Binary_trie() {
        tree.reserve(3e6); // Safe upper bound, adjust if needed
        tree.emplace_back(node()); // root
    }
 
    void insert(long long x, int cnt = 1) {
        int cur = 0;
        tree[cur].cnt += cnt;
        for (int bit = LOG; ~bit; --bit) {
            int to = !!(x & (1LL << bit));
            if (tree[cur].child[to] == -1) {
                tree[cur].child[to] = tree.size();
                tree.emplace_back(node());
            }
            cur = tree[cur].child[to];
            tree[cur].cnt += cnt;
        }
    }
 
    void erase(long long x) {
        int cur = 0;
        for (int bit = LOG; ~bit; --bit) {
            int to = !!(x & (1LL << bit));
            if (tree[cur].child[to] == -1 || tree[tree[cur].child[to]].cnt == 1) {
                tree[cur].child[to] = -1;
                return;
            }
            cur = tree[cur].child[to];
            tree[cur].cnt--;
        }
    }
 
    long long max_xor(long long x) {
        long long cur = 0, ret = 0;
        for (int bit = LOG; ~bit; bit--) {
            int to = !!(x & (1LL << bit));
            if (~tree[cur].child[!to]) {
                cur = tree[cur].child[!to];
                ret += !to * (1LL << bit);
            }
            else {
                cur = tree[cur].child[to];
                ret += to * (1LL << bit);
            }
        }
        return x ^ ret;
    }
 
    long long min_xor(long long x) {
        return -1 ^ max_xor(x ^ -1);
    }
 
    long long xor_greater_than_k(long long x, long long k) {
        int ret = 0, cur = 0;
        for (int bit = LOG; ~bit; --bit) {
            int take0 = 1, take1 = 1;
            if (((x ^ (1LL << bit)) & (LLONG_MAX << bit)) >= k && ~tree[cur].child[1]) {
                take1 = 0;
                ret += tree[tree[cur].child[1]].cnt;
            }
            if ((x & (LLONG_MAX << bit)) >= k && ~tree[cur].child[0]) {
                take0 = 0;
                ret += tree[tree[cur].child[0]].cnt;
            }
            if (~tree[cur].child[0] && take0 && ((((x ^ (1LL << bit)) | ~(LLONG_MAX << bit)) < k) || tree[cur].child[1] == -1 || !take1)) {
                cur = tree[cur].child[0];
            }
            else if (~tree[cur].child[1] && take1 && ((x | ~(LLONG_MAX << bit)) < k || tree[cur].child[0] == -1 || !take0)) {
                x ^= (1LL << bit);
                cur = tree[cur].child[1];
            }
            else {
                return ret;
            }
        }
        return ret;
    }
};