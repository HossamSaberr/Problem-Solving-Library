template < typename treeType = int, typename numsType = int, int Base = 0 >
class Segment_Tree {
private:
    int size, max_level;
    treeType DEFAULT;
    vector < treeType > tree;
    const function < treeType(const treeType&, const treeType&) > operation;

    // Build the segment tree
    void build(const vector < numsType >& nums, int idx, int lx, int rx) {
        if (Base ? lx >= int(nums.size()) : lx > int(nums.size())) return;
        if (rx == lx) tree[idx] = treeType(nums[lx - !Base]);
        else {
            int mx = (rx + lx) / 2;
            build(nums, idx * 2, lx, mx);
            build(nums, idx * 2 + 1, mx + 1, rx);
            tree[idx] = operation(tree[idx * 2], tree[idx * 2 + 1]);
        }
    }

    // Update the segment tree
    void update(int index, numsType value, int idx, int lx, int rx) {
        if (rx == lx) tree[idx] = treeType(value);
        else {
            int mx = (rx + lx) / 2;
            if (index <= mx) update(index, value, idx * 2, lx, mx);
            else update(index, value, idx * 2 + 1, mx + 1, rx);
            tree[idx] = operation(tree[idx * 2], tree[idx * 2 + 1]);
        }
    }

    // Query the segment tree
    treeType query(int l, int r, int idx, int lx, int rx) const {
        if (lx > r || l > rx) return DEFAULT;
        if (lx >= l && rx <= r) return tree[idx];
        int mx = (lx + rx) / 2;
        return operation(query(l, r, idx * 2, lx, mx), query(l, r, idx * 2 + 1, mx + 1, rx));
    }

public:

    Segment_Tree(
        int n = 0, 
        const vector < numsType >& nums = vector < numsType >(), 
        const function < treeType(const treeType&, const treeType&) >& op = [](const treeType& a, const treeType& b) { return a + b; },
        treeType def = 0
    ) : size(1), max_level(1), DEFAULT(def), operation(op) {
        while (size < n) size *= 2, max_level++;
        tree = vector < treeType > (2 * size, DEFAULT);
        if (!nums.empty()) build(nums, 1, 1, size);
    }

    void build(const vector < numsType >& nums) {
        build(nums, 1, 1, size);
    }

    void update(int index, numsType value) {
        update(index, value, 1, 1, size);
    }

    treeType query(int l, int r) const {
        return query(l, r, 1, 1, size);
    }

    treeType operator[](int index) const {
        return query(index, index, 1, 1, size);
    }

    // Print the segment tree as a pretty tree structure
    void print() const {
        if (tree.size() <= 1) return;
        int level = 0;
        queue < pair < int, int > > q;  // pair of (index in tree, level in tree)
        q.push({1, level});
        while (!q.empty()) {
            int nodesAtCurrentLevel = q.size();
            int spacesBetween = (1 << (max_level - level + 1)) - 1;
            int leadingSpaces = (1 << (max_level - level)) - 1;
            cout << string(leadingSpaces * 2, ' ');  // leading spaces for the first node in the level
            while (nodesAtCurrentLevel--) {
                auto [idx, lvl] = q.front();
                q.pop();
                cout << setw(2) << tree[idx];
                // Print spaces between nodes at the current level
                if (nodesAtCurrentLevel) cout << string(spacesBetween * 2, ' ');
                // Add children to the queue
                if (idx * 2 < tree.size()) {
                    q.push({idx * 2, lvl + 1});
                    q.push({idx * 2 + 1, lvl + 1});
                }
            }
            cout << "\n";  // new line for the new level
            level++;
        }
    }
};