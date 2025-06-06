#include <bits/stdc++.h>
using namespace std;

/*
    Persistent Segment Tree with Lazy‐Propagation
    ------------------------------------------------
    - Supports:
        * build(arr[])            → O(N)
        * update_range(v, l, r, x) → O(log N) per update (adds x to [l..r))
        * query_range(v, l, r)     → O(log N) per query
    - “versions” is a vector<Node*> of roots; version[i] is the root after the i-th modification.
    - Internally each Node stores: sum over its segment, a “lazy‐add” value, and left/right pointers.
    - Whenever we need to push or modify a node, we clone it (new Node) so as not to disturb older versions.
*/

//----------------------------------------------------------------------
// Node struct: each node covers some interval [L, R) in the conceptual array.
//   - sum: the total sum of that segment
//   - lazy: “pending add” that still needs to be propagated to children
//   - left, right: child pointers (can be nullptr for leaves)
//
// To keep things simple, we assume the array‐values and sums fit in 64‐bit.
//----------------------------------------------------------------------

struct Node {
    long long sum;    // sum of the segment
    long long lazy;   // pending addition to propagate
    Node* left;
    Node* right;

    // Leaf or “empty” constructor
    Node(long long v = 0) : sum(v), lazy(0), left(nullptr), right(nullptr) {}

    // Internal‐node constructor: combine two children
    Node(Node* l, Node* r) : lazy(0), left(l), right(r) {
        sum = 0;
        if (l) sum += l->sum;
        if (r) sum += r->sum;
    }
};

//----------------------------------------------------------------------
// build(0, N): builds a brand‐new segment tree over arr[0..N-1].
//----------------------------------------------------------------------

Node* build(int L, int R, int arr[]) {
    if (L + 1 == R) {
        // leaf
        return new Node(arr[L]);
    }
    int M = (L + R) >> 1;
    Node* lc = build(L, M, arr);
    Node* rc = build(M, R, arr);
    return new Node(lc, rc);
}

//----------------------------------------------------------------------
// clone_node(old): create a shallow copy of “old” (so we can mutate it).
// This is used whenever we “visit” a node in update/query, to preserve persistence.
//----------------------------------------------------------------------

inline Node* clone_node(Node* old) {
    if (!old) return new Node(0);
    Node* x = new Node();
    x->sum   = old->sum;
    x->lazy  = old->lazy;
    x->left  = old->left;
    x->right = old->right;
    return x;
}

//----------------------------------------------------------------------
// push(node, L, R): propagate node->lazy to its children, if any.
//   Splits [L,R) at M, clones children, and pushes the pending addition down.
//----------------------------------------------------------------------

void push(Node* &node, int L, int R) {
    if (!node) return;
    if (node->lazy == 0) return;  // nothing to push
    if (L + 1 == R) {
        // leaf: just apply and clear
        node->sum += node->lazy;
        node->lazy = 0;
        return;
    }

    // ensure we have children to push into
    int M = (L + R) >> 1;
    // clone node itself so we don’t overwrite older versions
    node = clone_node(node);

    // clone or create left child
    if (!node->left) {
        node->left = new Node(0);
    } else {
        node->left = clone_node(node->left);
    }
    // clone or create right child
    if (!node->right) {
        node->right = new Node(0);
    } else {
        node->right = clone_node(node->right);
    }

    // propagate “lazy” to children
    long long add = node->lazy;
    node->left->lazy  += add;
    node->right->lazy += add;

    // apply to children sums immediately
    node->left->sum  += add * (M - L);
    node->right->sum += add * (R - M);

    // clear current node’s lazy
    node->lazy = 0;

    // update own sum remains correct (it already included lazy)
}

//----------------------------------------------------------------------
// pull(node): recompute node->sum from children.  (Assumes children sums are correct.)
//----------------------------------------------------------------------

inline void pull(Node* node) {
    node->sum = 0;
    if (node->left)  node->sum += node->left->sum;
    if (node->right) node->sum += node->right->sum;
}

//----------------------------------------------------------------------
// update_range(old_root, L, R, ql, qr, x) → returns new_root
//   adds +x to every index in [ql..qr).  Works on the tree covering [L,R).
//----------------------------------------------------------------------

Node* update_range(Node* old, int L, int R, int ql, int qr, long long x) {
    // no overlap → reuse old node entirely
    if (R <= ql || qr <= L) {
        return old;
    }

    // fully inside: clone, apply lazy, and return
    if (ql <= L && R <= qr) {
        Node* node = clone_node(old);
        node->lazy += x;
        node->sum  += x * (R - L);
        return node;
    }

    // partial overlap: we must push down first, then recurse
    Node* node = clone_node(old);
    push(node, L, R);  // ensures children exist and get the pending lazy from “old”

    int M = (L + R) >> 1;
    node->left  = update_range(node->left,  L, M, ql, qr, x);
    node->right = update_range(node->right, M, R, ql, qr, x);

    pull(node);
    return node;
}

//----------------------------------------------------------------------
// query_range(root, L, R, ql, qr) → sum over [ql..qr) in version “root”
//----------------------------------------------------------------------

long long query_range(Node* node, int L, int R, int ql, int qr) {
    if (!node || R <= ql || qr <= L) {
        return 0;
    }
    if (ql <= L && R <= qr) {
        return node->sum;
    }

    push(node, L, R);  // clone‐on‐write will only happen if node->lazy != 0

    int M = (L + R) >> 1;
    long long left_sum  = query_range(node->left,  L, M, ql, qr);
    long long right_sum = query_range(node->right, M, R, ql, qr);
    return left_sum + right_sum;
}


//----------------------------------------------------------------------
// Example usage in main()
//----------------------------------------------------------------------

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    int* arr = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // Build version 0 from the initial array
    Node* root0 = build(0, N, arr);
    vector<Node*> versions;
    versions.push_back(root0);

    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            // type=1 v l r x  → create a new version by adding x to [l..r)
            int v, l, r;
            long long x;
            cin >> v >> l >> r >> x;
            Node* newRoot = update_range(versions[v], 0, N, l, r, x);
            versions.push_back(newRoot);
        }
        else if (type == 2) {
            // type=2 v l r  → query sum on version v over [l..r)
            int v, l, r;
            cin >> v >> l >> r;
            long long ans = query_range(versions[v], 0, N, l, r);
            cout << ans << "\n";
        }
    }

    delete[] arr;
    return 0;
}
