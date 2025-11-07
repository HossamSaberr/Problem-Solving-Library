
int n;
vector<vector<int>> adj;
vector<int> subsize , cd_parent , level;
vector<bool> removed;

int dfs_size(int u, int p) {
    subsize[u] = 1;
    for (int v : adj[u]) if (v != p && !removed[v]) {
        subsize[u] += dfs_size(v, u);
    }
    return subsize[u];
}

int find_centroid(int u, int p, int sz) {
    for (int v : adj[u]) {
        if (v != p && !removed[v]) {
            if (subsize[v] > sz / 2)
                return find_centroid(v, u, sz);
        }
    }
    return u;
}

void decompose(int start, int parent_centroid , int lvl) {
    int tot = dfs_size(start, -1);
    int centroid = find_centroid(start, -1, tot);

    cd_parent[centroid] = parent_centroid;
    level[centroid] = lvl;

    removed[centroid] = 1;

    for (int v : adj[centroid]) {
        if (!removed[v])
            decompose(v, centroid , lvl + 1);
    }
}
