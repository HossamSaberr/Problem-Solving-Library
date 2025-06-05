template <typename T = int, const int Base = 0>
class Lazy_Propagation {
private:
    struct Node {
        T val, lazy;       // `val` = sum over this segment; `lazy` = pending addition
        bool is_lazy;
        Node(T v = 0) : val(v), lazy(0), is_lazy(false) {}
    };

    int size;             // = power of two ≥ n
    int tree_left, tree_right;
    vector<Node> tree;
    T query_default = 0;
    T init_default  = 0;

    // Combines two Node‐values
    Node tree_operation(const Node &a, const Node &b) {
        Node ans;
        ans.val = applyToNodeValue(a.val, b.val, /*lx*/0, /*rx*/0);
        return ans;
    }

    // Combines two lazy tags.
    T lazy_operation(T old_lazy, T new_lazy) {
        return applyToLazyValue(old_lazy, new_lazy, /*lx*/0, /*rx*/0);
    }

    // Propagate the lazy tag at index `idx` down to its children.
    void propagate(int idx, int lx, int rx) {
        if (!tree[idx].is_lazy) return;
        // apply the pending addition to this node
        tree[idx].val = lazy_operation(tree[idx].val , (rx - lx + 1) * tree[idx].lazy);
        if (lx < rx) {
            // push the lazy tag to children
            int lc = idx * 2;
            int rc = idx * 2 + 1;
            tree[lc].lazy   = lazy_operation(tree[lc].lazy,   tree[idx].lazy);
            tree[rc].lazy   = lazy_operation(tree[rc].lazy,   tree[idx].lazy);
            tree[lc].is_lazy = tree[rc].is_lazy = true;
        }
        tree[idx].lazy = init_default;
        tree[idx].is_lazy = false;
    }

    // Build from a vector or from a single initial value
    void build(const vector<T> &nums, T initial_value, int idx, int lx, int rx) {
        // If this is a leaf, place either nums[lx−Base] (if within range) or `initial_value`
        if (lx == rx) {
            int pos = lx - Base;
            if (!nums.empty() && 0 <= pos && pos < (int)nums.size())
                tree[idx].val = nums[pos];
            else
                tree[idx].val = initial_value;
            return;
        }
        int mid = (lx + rx) / 2;
        build(nums, initial_value, idx * 2,     lx,    mid);
        build(nums, initial_value, idx * 2 + 1, mid + 1, rx);
        propagate(idx * 2,     lx,     mid);
        propagate(idx * 2 + 1, mid + 1, rx);
        tree[idx] = tree_operation(tree[idx * 2], tree[idx * 2 + 1]);
    }

    // Internal recursive update on [l..r], node covers [lx..rx]
    void update_rec(int l, int r, T v, int idx, int lx, int rx) {
        propagate(idx, lx, rx);
        if (lx > r || rx < l) {
            // no overlap
            return;
        }
        if (lx >= l && rx <= r) {
            // fully inside
            tree[idx].lazy = lazy_operation(tree[idx].lazy, v);
            tree[idx].is_lazy = true;
            propagate(idx, lx, rx);
            return;
        }
        int mid = (lx + rx) / 2;
        update_rec(l, r, v, idx * 2,     lx,    mid);
        update_rec(l, r, v, idx * 2 + 1, mid + 1, rx);
        propagate(idx * 2,     lx,    mid);
        propagate(idx * 2 + 1, mid + 1, rx);
        tree[idx] = tree_operation(tree[idx * 2], tree[idx * 2 + 1]);
    }

    // Internal recursive query of sum on [l..r], node covers [lx..rx]
    T query_rec(int l, int r, int idx, int lx, int rx) {
        propagate(idx, lx, rx);
        if (lx > r || rx < l) {
            return query_default;
        }
        if (lx >= l && rx <= r) {
            return tree[idx].val;
        }
        int mid = (lx + rx) / 2;
        T left_val  = query_rec(l, r, idx * 2,     lx,    mid);
        T right_val = query_rec(l, r, idx * 2 + 1, mid + 1, rx);
        return lazy_operation(left_val , right_val);
    }

public:

    function<T(T, T, int, int)> applyToNodeValue =
            [&](T a, T b, int, int) {
                return max(a, b);
            };

    function<T(T, T, int, int)> applyToLazyValue =
            [&](T old_lazy, T new_lazy, int, int) {
                return max(old_lazy, new_lazy);
            };
    // Constructor. `n` = size of the underlying array (in whatever base you choose).
    Lazy_Propagation(int n, const vector<T> &v = vector<T>()) {
        // Compute size = smallest power of two ≥ n
        size = 1;
        while (size < n) size <<= 1;
        // The internal leaves will cover [ Base .. (Base + size − 1) ].
        tree_left  = Base;
        tree_right = Base + (size - 1);
        tree.assign(2 * size, Node(init_default));

        if (!v.empty()) {
            // build from vector v (should have length = n)
            build(v, init_default, 1, tree_left, tree_right);
        }
    }

    // Build the entire tree with one initial value (e.g. 0 everywhere)
    void build(T initial_value) {
        build(vector<T>(), initial_value, 1, tree_left, tree_right);
    }

    // Build from a vector of length = n (zero-based in nums[0..n-1]).
    //   If Base = 0, then nums[0]→leaf(0), …, nums[n-1]→leaf(n-1).
    //   If Base = 1, then nums[0]→leaf(1), …, nums[n-1]→leaf(n).
    void build(const vector<T> &nums) {
        build(nums, init_default, 1, tree_left, tree_right);
    }

    // Public single‐index update: add `v` to position i
    //   If you used Base=0, call .update(i, i, v) with i∈[0..n−1].
    //   If you used Base=1, call .update(i, i, v) with i∈[1..n].
    void update(int i, T v) {
        update_rec(i, i, v, 1, tree_left, tree_right);
    }

    // Public range update: add `v` to every element in [l..r].
    //   If Base=0, you must call .update(l, r, v) with l,r ∈ [0..n−1], l ≤ r.
    //   If Base=1, you must call .update(l, r, v) with l,r ∈ [1..n], l ≤ r.
    void update(int l, int r, T v) {
        update_rec(l, r, v, 1, tree_left, tree_right);
    }

    // Public range query: return sum over [l..r].
    //   If Base=0, call .query(l, r) with l,r ∈ [0..n−1].
    //   If Base=1, call .query(l, r) with l,r ∈ [1..n].
    T query(int l, int r) {
        return query_rec(l, r, 1, tree_left, tree_right);
    }

    // Get the single element at index i.
    T get(int i) {
        return query(i, i);
    }

    // (Optional) Print the tree levels with lazy propagation applied,
    // just for debugging. Not required for correct operation.
    void print_debug() {
        if (tree.size() <= 1) return;
        int levels = 0;
        // compute max depth from size
        while ((1 << levels) < (int)tree.size()) levels++;

        queue<tuple<int, int, int, int>> q;
        // (node_index, depth, lx, rx)
        q.push({1, 0, tree_left, tree_right});
        while (!q.empty()) {
            int sz = q.size();
            int depth = std::get<1>(q.front());
            int spaces_between = (1 << (levels - depth + 1)) - 1;
            int leading_spaces = (1 << (levels - depth)) - 1;
            cout << string(leading_spaces * 2, ' ');

            while (sz--) {
                auto [idx, d, lx, rx] = q.front();
                q.pop();
                propagate(idx, lx, rx);
                cout << setw(3) << tree[idx].val;
                if (sz) cout << string(spaces_between * 2, ' ');
                if (idx * 2 < (int)tree.size()) {
                    int mid = (lx + rx) / 2;
                    q.push({idx * 2,     d + 1, lx,      mid});
                    q.push({idx * 2 + 1, d + 1, mid + 1, rx});
                }
            }
            cout << "\n";
        }
    }
};






/*
     Lazy_Propagation<int , 0> lazy_seg_sum(n);
    lazy_seg.build(0);
    lazy_seg.applyToLazyValue = [&] (int oldlazy , int newlazy , int lx , int rx) {
        return oldlazy+newlazy;
    };
    lazy_seg.applyToNodeValue = [&] (int a , int b , int lx , int rx) {
        return a + b;
    };


     Lazy_Propagation<int , 0> lazy_seg_mx(n);
    lazy_seg.build(0);
    lazy_seg.applyToLazyValue = [&] (int oldlazy , int newlazy , int lx , int rx) {
        return max(oldlazy,newlazy);
    };
    lazy_seg.applyToNodeValue = [&] (int a , int b , int lx , int rx) {
        return max(a , b);
    };
*/