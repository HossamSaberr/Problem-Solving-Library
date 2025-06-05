#include <vector>
#include <queue>
#include <limits>

using namespace std;

struct SPFA {
    int n;
    vector<vector<pair<int, int>>> adj;
    vector<int> dist, count;
    vector<bool> inQueue;
    const int INF = numeric_limits<int>::max();

    SPFA(int nodes) : n(nodes) {
        adj.resize(n);
    }

    void add_edge(int u, int v, int w) {
        adj[u].emplace_back(v, w);
    }

    // Returns true if no negative cycle, false otherwise
    bool run(int src) {
        dist.assign(n, INF);
        count.assign(n, 0);
        inQueue.assign(n, false);
        queue<int> q;

        dist[src] = 0;
        q.push(src);
        inQueue[src] = true;
        count[src]++;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            inQueue[u] = false;

            for (auto &[v, w] : adj[u]) {
                if (dist[u] != INF && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    if (!inQueue[v]) {
                        q.push(v);
                        inQueue[v] = true;
                        count[v]++;
                        if (count[v] > n) return false; // Negative cycle detected
                    }
                }
            }
        }
        return true;
    }

    int get_distance(int v) {
        return dist[v];
    }

    vector<int> get_all_distances() {
        return dist;
    }
};
