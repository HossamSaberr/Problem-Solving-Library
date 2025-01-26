// atcoder : https://atcoder.jp/contests/abc390/tasks/abc390_e
/*
بسم الله الرحمن الرحيم

الْحَمْدُ لِلّهِ الَّذِي هَدَانَا لِهَـذَا وَمَا كُنَّا لِنَهْتَدِيَ لَوْلا أَنْ هَدَانَا اللّهُ

اللهم حرر فلسطين من كيد الصهاينة واجعل كيدهم في نحورهم
اللهم انصر الأقصى والقدس وأهالي غزة وفلسطين اللهم اطمس على أعداء الدين والمدنسين
*/

#include <bits/stdc++.h>

using namespace std;

const long double pii = 3.1415926536;
#define int long long
#define endl '\n'
#define Shity ios_base::sync_with_stdio(false);
#define Code cin.tie(nullptr);cout.tie(nullptr);
#define By int t = 1;//cin >> t;
#define Hossam while(t--) { solve(); }
#define all(x) begin(x), end(x)
#define NO cout << "No" << endl
#define YES cout << "Yes" << endl
#define init memset(dp , -1 , sizeof dp) // Note : Never use it with N = 2 * 1e5 !!! && use it with 0 , -1 only (because it fills each "byte" `not the whole int` with 0x0 ansing a 0 or 0xFF ansing -1) AND it make it in O(N) if you use vector use std::fill instead

void Free_Palestine() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void solve() {
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> v1, v2, v3;
    for (int i = 0; i < n; ++i) {
        int v, a, c;
        cin >> v >> a >> c;
        if (v == 1)
            v1.emplace_back(a, c);
        if (v == 2)
            v2.emplace_back(a, c);
        if (v == 3)
            v3.emplace_back(a, c);
    }
    vector<int> dp1(x + 1, -1), dp2(x + 1, -1), dp3(x + 1, -1);
    dp1[0] = dp2[0] = dp3[0] = 0;
    for (auto [a, c] : v1) {
        for (int i = x; i >= c; --i) {
            if (dp1[i - c] != -1)
                dp1[i] = max(dp1[i], dp1[i - c] + a);
        }
    }
    for (auto [a, c] : v2) {
        for (int i = x; i >= c; --i) {
            if (dp2[i - c] != -1)
                dp2[i] = max(dp2[i], dp2[i - c] + a);
        }
    }
    for (auto [a, c] : v3) {
        for (int i = x; i >= c; --i) {
            if (dp3[i - c] != -1)
                dp3[i] = max(dp3[i], dp3[i - c] + a);
        }
    }
    for (int i = 1; i <= x; ++i) {
        dp1[i] = max(dp1[i - 1], dp1[i]);
    }
    for (int i = 1; i <= x; ++i) {
        dp2[i] = max(dp2[i - 1], dp2[i]);
    }
    for (int i = 1; i <= x; ++i) {
        dp3[i] = max(dp3[i - 1], dp3[i]);
    }
    if (dp1[x] == -1 || dp2[x] == -1 || dp3[x] == -1)
        return void(cout << 0 << endl);
    int ans = 0;
    for (int i = 0; i <= x; ++i) {
        for (int j = 0; j <= x - i; ++j) {
            int k = x - i - j;
            if (k < 0)
                continue;
            int mx = min({dp1[i], dp2[j], dp3[k]});
            ans = max(ans, mx);
        }
    }
    cout << ans << endl;
}

int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}
// الحمدلله رب العالمين