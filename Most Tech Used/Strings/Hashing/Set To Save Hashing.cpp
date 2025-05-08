template<typename K>
struct Hash {
    static constexpr float MAX_LOAD = 0.5f;
    static constexpr size_t EMPTY = (size_t)-1;

    struct Bucket { K key; size_t hash; };
    vector<Bucket> B;
    size_t sz=0, cap=0, thresh=0;

    Hash(size_t n=0){ rehash(n); }
    void rehash(size_t n){
        cap = 1;
        while(cap < (size_t)(n / MAX_LOAD)) cap <<= 1;
        B.assign(cap, {K(), EMPTY});
        sz = 0;
        thresh = (size_t)(cap * MAX_LOAD);
    }
    bool insert(const K &k){
        if(sz+1 > thresh) {
            auto old = move(B);
            rehash(cap*2);
            for(auto &b : old) if(b.hash!=EMPTY)
                    insert(b.key);
        }
        size_t h = (size_t)k ^ ((size_t)k>>23);
        size_t i = h & (cap-1);
        while(true){
            if(B[i].hash==EMPTY){
                B[i].hash = h;
                B[i].key  = k;
                ++sz;
                return true;
            }
            else if(B[i].hash==h && B[i].key==k){
                return false;
            }
            i = (i+1) & (cap-1);
        }
    }
    bool count(const K &k) const {
        size_t h = (size_t)k ^ ((size_t)k>>23);
        size_t i = h & (cap-1);
        while(true){
            if(B[i].hash==EMPTY)      return false;
            else if(B[i].hash==h && B[i].key==k) return true;
            i = (i+1) & (cap-1);
        }
    }
};

unsigned long long hashh[26];

void solve() {
    int n , q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<unsigned long long > prefix_hash(n + 1 , 0);
    for(int i = 0; i < n; ++i){
        prefix_hash[i + 1] = prefix_hash[i] + hashh[s[i] - 'a'];
    }
    vector<string> query(q) , ans(q , "NO");
    vector<vector<int>> a(n + 1);
    vector<int> uniq;
    uniq.reserve(q);
    for(int i = 0; i < q; i++){
        cin >> query[i];
        if(a[query[i].size()].empty())
            uniq.push_back(query[i].size());
        a[query[i].size()].push_back(i);
    }
    Hash<unsigned long long> hsh(n+1);
    for(auto &it : uniq) {
        hsh.rehash(n - it + 1);
        for(int i = 0; i + it <= n; i++){
            unsigned long long hashval = prefix_hash[i + it] - prefix_hash[i];
            hsh.insert(hashval);
        }
        for(auto &x : a[it]) {
            unsigned long long  hashval = 0;
            for(auto c : query[x])
                hashval += hashh[c - 'a'];
            if(hsh.count(hashval))
                ans[x] = "YES";
        }
    }
    for(auto &it : ans)
        cout << it << endl;
    for(auto &x : uniq)
        a[x].clear();
}

int32_t main() {
    mt19937_64 rng( chrono::high_resolution_clock::now().time_since_epoch().count() );
    for(int i = 0; i < 26; i++){
        hashh[i] = rng();
    }
    solve();
    return 0;
}