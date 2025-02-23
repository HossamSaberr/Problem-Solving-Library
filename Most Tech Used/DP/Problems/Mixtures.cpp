// spoj : https://www.spoj.com/problems/MIXTURES/en/
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
#define all(x) rbegin(x), rend(x)
#define NO cout << "NO" << endl
#define YES cout << "YES" << endl
#define init memset(dp , -1 , sizeof dp) // Note : Never use it with N = 2 * 1e5 !!! && use it with 0 , -1 only (because it fills each "byte" `not the whole int` with 0x0 ansing a 0 or 0xFF ansing -1) AND it make it in O(N) if you use vector use std::fill instead

void Free_Palestine() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

const int N = 150;

int n , h[N] , pre[N] , dp[N][N];

int idk(int l , int r) {
    if (l == r)
        return 0;
    int &ret = dp[l][r];
    if(~ret)
        return ret;
    ret = 1e18;
    for (int i = l; i < r; ++i) {
        int ll = (pre[i] - (l > 0 ? pre[l - 1] : 0)) % 100 , rr = (pre[r] - pre[i]) % 100;
        ret = min(ret , idk(l , i) + idk(i + 1 , r) + ll * rr);
    }
    return ret;
}

void solve() {
    while(cin >> n) {
        memset(pre , 0 , sizeof pre);
        for (int i = 0; i < n; ++i) {
            cin >> h[i];
        }
        for (int i = 1; i <= n; ++i) {
            pre[i] = pre[i - 1] + h[i - 1];
        }
        init;
        cout << idk(1 , n) << endl;
    }
}

int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}
// الحمدلله رب العالمين