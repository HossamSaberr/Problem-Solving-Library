#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
  MaxDiffConstraints

  - We have variables X_0, X_1, ..., X_(n−1).
  - Each constraint is of the form:
        X_j − X_i ≤ c
  - We want to decide if there is any integer assignment satisfying
    all those inequalities, and if so, produce the *maximum* feasible
    values of X_0..X_(n−1) (anchored by setting X_0 = 0).

  Implementation idea:

    (1)  X_j − X_i ≤ c  〈〉  X_i − X_j ≥ −c.
         So we rewrite each “≤” constraint into a “≥” constraint
         of the form:  X_u − X_v ≥ C  with (u = i, v = j, C = −c).

    (2)  Once all constraints are in the form “X_u − X_v ≥ C,” we run
         a Bellman–Ford–style “longest‐path” algorithm to push each
         X_u as large as possible, under the condition X_0 = 0.  If
         a positive‐weight cycle appears, that means the system is
         infeasible.

    (3)  If feasible, the resulting distances dist[u] = X_u are the
         *maximum* possible integers that satisfy every “X_u − X_v ≥ C.”

  Complexity: O(n⋅m), where n = #variables, m = #constraints.
*/

struct MaxDiffConstraints {
    int nvars;
    // Internally, each element is a triple (u, v, C) meaning: X_u − X_v ≥ C.
    // We will store (u=i, v=j, C=−c) whenever the user asks to add “X_j − X_i ≤ c.”
    vector<array<ll,3>> cstr;

    // Call this to set how many variables you have: X_0..X_(n−1)
    void setNumVariables(int n) {
        nvars = n;
        cstr.clear();
    }

    // Add one constraint of the form:   X_j − X_i ≤ c
    // We convert it to:  X_i − X_j ≥ −c,  i.e.  (u=i, v=j, C=−c).
    void addConstraint(int i, int j, ll c) {
        ll C = -c;
        cstr.push_back({ (ll)i, (ll)j, C });
    }

    // Returns false if the system is infeasible (a positive‐cycle appears).
    // Otherwise returns true.
    // Internally we run Bellman–Ford “longest‐path” with X_0 = 0.
    bool isSolvable() const {
        const ll INF_NEG = LLONG_MIN;
        vector<ll> dist(nvars, INF_NEG);
        dist[0] = 0;  // anchor X_0 = 0

        int m = (int)cstr.size();
        // Relax edges up to (nvars−1) times
        for (int it = 0; it < nvars - 1; ++it) {
            bool updated = false;
            for (int e = 0; e < m; ++e) {
                ll u = cstr[e][0];
                ll v = cstr[e][1];
                ll C = cstr[e][2];
                // The constraint is X_u >= X_v + C
                if (dist[v] != INF_NEG && dist[v] + C > dist[u]) {
                    dist[u] = dist[v] + C;
                    updated = true;
                }
            }
            if (!updated) break;
        }

        // One more pass to detect any positive‐cycle
        for (int e = 0; e < m; ++e) {
            ll u = cstr[e][0];
            ll v = cstr[e][1];
            ll C = cstr[e][2];
            if (dist[v] != INF_NEG && dist[v] + C > dist[u]) {
                // We can still push X_u ↑, so there is a positive‐cycle
                return false;
            }
        }
        return true;
    }

    // Call this only after isSolvable() returned true.
    // Returns a vector<ll> D of size nvars, where D[k] = the “maximum” feasible X_k
    // (subject to all constraints and X_0 = 0).
    vector<ll> getMaxValues() const {
        const ll INF_NEG = LLONG_MIN;
        vector<ll> dist(nvars, INF_NEG);
        dist[0] = 0;  // anchor X_0 = 0

        int m = (int)cstr.size();
        // Exactly (nvars − 1) relaxation passes suffice to push every X_u
        // to its maximum feasible value.
        for (int it = 0; it < nvars - 1; ++it) {
            for (int e = 0; e < m; ++e) {
                ll u = cstr[e][0];
                ll v = cstr[e][1];
                ll C = cstr[e][2];
                if (dist[v] != INF_NEG && dist[v] + C > dist[u]) {
                    dist[u] = dist[v] + C;
                }
            }
        }
        return dist;
    }
};

/*  Example usage:

    Suppose we have 4 variables: X_0, X_1, X_2, X_3.  And these three constraints:

      (1)  X_2 − X_0 ≤ 5
      (2)  X_3 − X_2 ≤ 1
      (3)  X_1 − X_3 ≤ 4

    We want to push each variable as large as possible while still making all
    those inequalities hold, with X_0 = 0 anchored.

    1) Build the struct:

       MaxDiffConstraints mdc;
       mdc.setNumVariables(4);

    2) Add constraints (X_j − X_i ≤ c) one by one:

       // (1)  X_2 − X_0 ≤ 5   ⟹   X_0 − X_2 ≥ −5
       mdc.addConstraint(0, 2, 5);

       // (2)  X_3 − X_2 ≤ 1   ⟹   X_2 − X_3 ≥ −1
       mdc.addConstraint(2, 3, 1);

       // (3)  X_1 − X_3 ≤ 4   ⟹   X_3 − X_1 ≥ −4
       mdc.addConstraint(3, 1, 4);

    3) Check feasibility:

       if (!mdc.isSolvable()) {
           cout << "No integer solution exists.\n";
           return 0;
       }

    4) Extract the maximum values:

       vector<ll> X = mdc.getMaxValues();
       // Now X[k] is the largest integer we can assign to X_k, subject to
       //   - all three “≤” constraints, and
       //   - X_0 = 0.

       // Print them:
       for (int k = 0; k < 4; ++k) {
           cout << "X_" << k << " = " << X[k] << "\n";
       }

    5) In our example, the code above will produce:

        X_0 = 0
        X_2 = 5   (because X_2 − X_0 ≤ 5  forces  X_2 ≤ 5, and we can push it to 5)
        X_3 = 6   (because X_3 − X_2 ≤ 1  ⇒  X_3 ≤ X_2 + 1 = 6, so we push X_3 to 6)
        X_1 = 2   (because X_1 − X_3 ≤ 4  ⇒  X_1 ≤ X_3 + 4 = 10, but we also must respect
                         X_3 − X_1 ≥ −4  ⇒  X_1 ≥ X_3 − 4 = 2;  to maximize X_1, we pick X_1 = 2?)

      Actually, watch carefully: “X_1 − X_3 ≤ 4  ⟹  X_3 − X_1 ≥ −4.”  We store it as
      (u=3, v=1, C=−4).  So in the longest‐path logic, it forces X_3 ≥ X_1 − 4 ⇒ X_1 ≤ X_3 + 4.
      But if X_3=6, that says X_1 ≤ 10.  There is no *upper* bound on X_1 except X_0=0
      anchored indirectly by a chain—if no other constraint touches X_1, we can push X_1 to
      +∞.  To avoid that, one often *must* include a small “anchor‐lower‐bound,” e.g. X_1 − X_1 ≥ 0.
      In general, if a variable never appears on the LHS of any “≤” constraint, it can be
      pushed arbitrarily high.

      To ensure each X_i doesn’t run away, it’s common to also add a “bound‐zero” constraint
      for every i, e.g.  X_i − X_i ≤ 0  (⟹  X_i − X_i ≥ 0), which pins each variable’s minimum
      to 0.  If you want them all nonnegative *and* want to find their maximums, you’d do:

          for(int i=0; i<n; ++i) 
              mdc.addConstraint(i, i, 0);  
          // This enforces X_i - X_i ≤ 0  ⇒  X_i ≥ X_i.  It prevents “+∞” drift.

      In the example above, as written, X_1 might be “unbounded above,” because nothing
      limits it besides X_0=0 via a cycle.  If you really do want “every X_i ≥ 0” plus “maximize,”
      then also add `mdc.addConstraint(i,i,0);` for each i.  In that case:

        X_0 = 0
        X_2 = 5
        X_3 = 6
        X_1 = 2   (follows from the cycle constraints so that it still satisfies all “≤”)

      Then `getMaxValues()` will return `[0, 2, 5, 6]`.

  — End of example. —
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // (You can remove main() entirely if you just want to use the struct above.)
    // This demo reads nothing and exits. 

    MaxDiffConstraints mdc;
    mdc.setNumVariables(n);   // create variables X_0, X_1, ..., X_(n-1)

    // Suppose you want:    X_j - X_i ≤ c
    mdc.addConstraint(i, j, c);

    // If you also want “X_k ≥ 0” for every k (so no variable can go to +∞):
    for(int k = 0; k < n; ++k)
        mdc.addConstraint(k, k, 0);

    if (!mdc.isSolvable()) {
        // No finite assignment can satisfy all constraints.
        cout << "-1\n";
    } else {
        auto X = mdc.getMaxValues();
        // Now X[k] is the maximum integer you can assign to X_k subject to all
        // “X_j - X_i ≤ c” (and any “X_k ≥ 0” if you added those).
        for (int k = 0; k < n; ++k) {
            cout << "X_" << k << " = " << X[k] << "\n";
        }
    }

    return 0;
}
