// A Fenwick Tree (Binary Indexed Tree) template with support for 0-based or 1-based indexing
template<bool one_based = true>
struct FenwickTree {
    vector<int> bit; // Internal BIT array for storing prefix sums
    int n;           // Size of the array (internally adjusted to n+1 for 1-based indexing)

    // Constructor: initialize BIT of size n (n+1 for 1-based)
    FenwickTree(int n) {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }

    // Constructor: initialize BIT from an existing array `a`
    // Automatically builds the tree by applying point updates
    FenwickTree(vector<int> a)
            : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            update(i + one_based, a[i]);
    }

    // Query prefix sum from index 1 to idx (or 0 to idx if 0-based)
    int query(int idx) {
        int ret = 0;
        // Adjust index if tree is 0-based
        for (idx += (!one_based); idx > 0; idx -= idx & -idx){
            ret += bit[idx];
        }
        return ret;
    }

    // Query sum in range [l, r]
    int query(int l, int r) {
        return query(r) - (l - 1 >= 0 ? query(l - 1) : 0);
    }

    // Add `delta` to index `idx`
    void update(int idx, int delta) {
        // Adjust index if tree is 0-based
        for (idx += (!one_based); idx < n; idx += idx & -idx){
            bit[idx] += delta;
        }
    }

    // Add `val` to the entire range [l, r] (requires special BIT logic)
    void update_range(int l, int r, int val) {
        update(l, val);
        update(r + 1, -val);
    }

    // Returns the smallest index such that the prefix sum ≥ x
    int lower_bound(int x) {
        int idx = 0, mask = 1;
        // Find the highest power of 2 ≤ n
        while (mask < n) mask <<= 1;
        for (mask >>= 1; mask > 0; mask >>= 1) {
            if (idx + mask < n && bit[idx + mask] < x) {
                x -= bit[idx + mask];
                idx += mask;
            }
        }
        return idx + one_based;
    }

    // Returns the smallest index such that the prefix sum > x
    int upper_bound(int x) {
        int idx = 0, mask = 1;
        while (mask < n) mask <<= 1;
        for (mask >>= 1; mask > 0; mask >>= 1) {
            if (idx + mask < n && bit[idx + mask] <= x) {
                x -= bit[idx + mask];
                idx += mask;
            }
        }
        return idx + one_based;
    }
};