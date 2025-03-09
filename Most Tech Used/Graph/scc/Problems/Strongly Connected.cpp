// geeksforgeeks : https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1?utm_source=youtube

class Solution {
    private:
        void add_edge(int u, int v, vector<vector<int>> &adj, vector<vector<int>> &adj_rev) {
            adj_rev[v].push_back(u);
        }
    
        void dfs1(int v, vector<int> &order, vector<bool> &used, vector<vector<int>> &adj) {
            used[v] = true;
            for (auto u : adj[v])
                if (!used[u])
                    dfs1(u, order, used, adj);
            order.push_back(v);
        }
    
        void dfs2(int v, vector<int> &component, vector<bool> &used, vector<vector<int>> &adj_rev) {
            used[v] = true;
            component.push_back(v);
            for (auto u : adj_rev[v])
                if (!used[u])
                    dfs2(u, component, used, adj_rev);
        }
    
    public:
        int kosaraju(vector<vector<int>> &adj) {
            int n = adj.size();
            vector<vector<int>> adj_rev(n);
            vector<bool> used(n, false);
            vector<int> order, component;
            for (int u = 0; u < n; ++u) {
                for (int v : adj[u]) {
                    add_edge(u, v, adj, adj_rev);
                }
            }
            for (int i = 0; i < n; ++i) {
                if (!used[i]) {
                    dfs1(i, order, used, adj);
                }
            }
            fill(used.begin(), used.end(), false);
            reverse(order.begin(), order.end());
            vector<vector<int>> sccs;
            for (auto v : order) {
                if (!used[v]) {
                    component.clear();
                    dfs2(v, component, used, adj_rev);
                    sccs.push_back(component);
                }
            }
    
            return sccs.size();
        }
    };
    