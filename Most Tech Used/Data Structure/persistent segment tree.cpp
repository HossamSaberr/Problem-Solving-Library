#include <bits/stdc++.h>
using namespace std;

// -----------------------------------------------------------------------------
// Persistent Segment Tree (point‐update + range‐sum queries) – 0-based indexing
// -----------------------------------------------------------------------------

struct Node {
    long long val;  // stores the combined value for the segment
    Node* left;
    Node* right;
    
    // Leaf constructor
    Node(long long v) : val(v), left(nullptr), right(nullptr) {}
    
    // Internal‐node constructor: combine two children
    Node(Node* l, Node* r) : left(l), right(r) {
        val = 0;
        if (l) val += l->val;
        if (r) val += r->val;
    }
};

// Build the initial tree over arr[l..r-1]
//   l, r: current segment (half-open: [l, r))
//   arr: pointer to the original array of size N
Node* build(int l, int r, int arr[]) {
    if (l + 1 == r) {
        // Leaf node
        return new Node(arr[l]);
    }
    int m = (l + r) >> 1;
    Node* leftChild  = build(l, m, arr);
    Node* rightChild = build(m, r, arr);
    return new Node(leftChild, rightChild);
}

// Create a new version by updating position 'pos' to 'newVal'
//   node: pointer to the root of the previous version (covering [l, r))
//   l, r: current segment
//   pos: index to update (0-based)
//   newVal: new value to assign at arr[pos]
Node* update(Node* node, int l, int r, int pos, int newVal) {
    if (l + 1 == r) {
        // Create a new leaf with updated value
        return new Node(newVal);
    }
    int m = (l + r) >> 1;
    if (pos < m) {
        // Update goes into the left subtree; right subtree is shared
        Node* newLeft = update(node->left, l, m, pos, newVal);
        return new Node(newLeft, node->right);
    } else {
        // Update into the right subtree; left subtree is shared
        Node* newRight = update(node->right, m, r, pos, newVal);
        return new Node(node->left, newRight);
    }
}

// Query the sum over [ql, qr) in the version whose root is 'node'
//   node: current node covering [l, r)
//   l, r: segment of this node
//   ql, qr: query interval (half-open [ql, qr))
long long query(Node* node, int l, int r, int ql, int qr) {
    if (!node || qr <= l || r <= ql) {
        // No overlap
        return 0;
    }
    if (ql <= l && r <= qr) {
        // Total overlap
        return node->val;
    }
    int m = (l + r) >> 1;
    return query(node->left,  l, m, ql, qr)
         + query(node->right, m, r, ql, qr);
}

// -----------------------------------------------------------------------------
// Example usage
// -----------------------------------------------------------------------------
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    int* arr = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // Build version 0
    Node* root0 = build(0, N, arr);
    vector<Node*> versions;
    versions.push_back(root0);

    // Process Q operations:
    // Each operation is either:
    //   1 v pos newVal   → create a new version by updating version v at index pos to newVal
    //   2 v l r           → query the sum on version v over [l, r) and print it
    //
    // Versions are 0-indexed in the 'versions' vector. When you do an update, you push_back
    // the new root so its index becomes the next version number.
    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int v, pos, newVal;
            cin >> v >> pos >> newVal;
            // create version v_new = update( versions[v], pos, newVal )
            Node* newRoot = update(versions[v], 0, N, pos, newVal);
            versions.push_back(newRoot);
        }
        else if (type == 2) {
            int v, l, r;
            cin >> v >> l >> r;
            long long ans = query(versions[v], 0, N, l, r);
            cout << ans << "\n";
        }
    }

    delete[] arr;
    return 0;
}
