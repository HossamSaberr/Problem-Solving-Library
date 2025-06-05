#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
  MinDiffConstraints

  - We have variables X_0, X_1, ..., X_(n−1).
  - Each constraint is of the form:
        X_j − X_i ≤ c
  - We want to decide if there is any integer assignment satisfying
    all those inequalities, and if so, produce the *minimum* feasible
    values of X_0..X_(n−1) (anchored by setting X_0 = 0).

  Implementation:

    • Store each “X_j − X_i ≤ c” as a directed edge (u=i, v=j, w=c).
      That means “dist[v] ≤ dist[u] + w”.

    • Run Bellman–Ford (shortest‐path) from X_0=0.  If a negative‐cycle
      is detected, the system is infeasible.  Otherwise, the final
      dist[k] is the minimum integer value for X_k that satisfies
      all constraints.

  Complexity: O(n⋅m), where n = #variables, m = #constraints.
*/

struct MinDiffConstraints {
    int nvars;
    // Each element is (u, v, w) representing X_j - X_i ≤ w  ⟺  dist[v] ≤ dist[u] + w
    vector<array<ll,3>> edges;

    // Call this to set how many variables you have: X_0..X_(n−1)
    void setNumVariables(int n) {
        nvars = n;
        edges.clear();
    }

    // Add one constraint: X_j − X_i ≤ c
    // Internally this is stored as edge (u=i, v=j, w=c).
    void addConstraint(int i, int j, ll c) {
        edges.push_back({ (ll)i, (ll)j, c });
    }

    // Returns false if the system is infeasible (negative‐cycle detected).
    // Otherwise returns true.
    bool isSolvable() const {
        const ll INF = LLONG_MAX;
        vector<ll> dist(nvars, INF);
        dist[0] = 0;  // anchor X_0 = 0

        int m = (int)edges.size();
        // Relax edges up to (nvars−1) times
        for (int it = 0; it < nvars - 1; ++it) {
            bool updated = false;
            for (auto &e : edges) {
                ll u = e[0], v = e[1], w = e[2];
                if (dist[u] != INF && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    updated = true;
                }
            }
            if (!updated) break;
        }

        // One more pass to detect a negative‐cycle
        for (auto &e : edges) {
            ll u = e[0], v = e[1], w = e[2];
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                return false;
            }
        }
        return true;
    }

    // Call this only after isSolvable() returned true.
    // Returns a vector<ll> dist[] of size nvars, where dist[k] is the
    // minimum integer X_k satisfying all “X_j − X_i ≤ c”.
    vector<ll> getMinValues() const {
        const ll INF = LLONG_MAX;
        vector<ll> dist(nvars, INF);
        dist[0] = 0;  // anchor X_0 = 0

        int m = (int)edges.size();
        // Exactly (nvars−1) relaxation passes suffice to find all shortest paths
        for (int it = 0; it < nvars - 1; ++it) {
            for (auto &e : edges) {
                ll u = e[0], v = e[1], w = e[2];
                if (dist[u] != INF && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }
        return dist;
    }
};

/* Example usage:

   Suppose we have 4 variables X_0, X_1, X_2, X_3 and these constraints:

     (1)  X_2 − X_0 ≤ 5
     (2)  X_3 − X_2 ≤ 1
     (3)  X_1 − X_3 ≤ 4

   We want the minimum X_0..X_3 (with X_0=0) that satisfy all.

   int main() {
       MinDiffConstraints mdc;
       mdc.setNumVariables(4);

       // Add: X_2 - X_0 ≤ 5
       mdc.addConstraint(0, 2, 5);

       // Add: X_3 - X_2 ≤ 1
       mdc.addConstraint(2, 3, 1);

       // Add: X_1 - X_3 ≤ 4
       mdc.addConstraint(3, 1, 4);

       if (!mdc.isSolvable()) {
           cout << "Infeasible\n";
           return 0;
       }

       auto X = mdc.getMinValues();
       for (int i = 0; i < 4; i++) {
           cout << "X_" << i << " = " << X[i] << "\n";
       }
       return 0;
   }

   In this example, one valid minimum solution is:
     X_0 = 0
     X_2 = 5    (must satisfy X_2 ≤ X_0 + 5)
     X_3 = 6    (so that X_3 ≤ X_2 + 1 = 6)
     X_1 = 10   (so that X_1 ≤ X_3 + 4 = 10)

   The code will produce exactly those minimum values. 
*/
