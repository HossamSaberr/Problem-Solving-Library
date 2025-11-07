
    int size;
    vector<Node> tree;
 
    void init(const vector<int>& arr) {
        int n = arr.size();
        size = 1;
        while(size < n) size *= 2;
        tree.assign(2 * size, {-1, 0});
        for (int i = 0; i < n; i++) {
            tree[size + i] = {arr[i], 1};
        }
        for (int i = n; i < size; i++) {
            tree[size + i] = {-1, 0};
        }
        for (int i = size - 1; i >= 1; i--) {
            tree[i] = combine(tree[2*i], tree[2*i+1]);
        }
    }
 
    Node query(int l, int r) {
        Node leftRes = {-1, 0};
        Node rightRes = {-1, 0};
        l += size; r += size;
        while(l < r) {
            if(l & 1) {
                leftRes = combine(leftRes, tree[l]);
                l++;
            }
            if(r & 1) {
                r--;
                rightRes = combine(tree[r], rightRes);
            }
            l /= 2; r /= 2;
        }
        return combine(leftRes, rightRes);
    }
};