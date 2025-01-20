// Codeforces : https://codeforces.com/problemset/problem/987/C
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
#define NO cout << "NO" << endl
#define YES cout << "YES" << endl
#define init memset(dp , INT_MAX , sizeof dp)

void Free_Palestine() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void solve() {
    int n;
    cin >> n;
    vector<int> h(n), o(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> o[i];
    }
    vector<int> l(n , INT_MAX) , r(n , INT_MAX);
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (h[j] < h[i])
                l[i] = min(l[i] , o[j]);
        }
    }
    for (int i = n - 2; i >= 0; --i) {
        for (int j = n - 1; j > i; --j) {
            if (h[j] > h[i])
                r[i] = min(r[i] , o[j]);
        }
    }
    int ans = INT_MAX;
    for (int i = 1; i < n - 1; ++i) {
        if (l[i] != INT_MAX && r[i] != INT_MAX)
            ans = min(ans , l[i] + o[i] + r[i]);
    }
    if (ans != INT_MAX)
        cout << ans << endl;
    else
        cout << -1 << endl;
}

int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}
// الحمدلله رب العالمين