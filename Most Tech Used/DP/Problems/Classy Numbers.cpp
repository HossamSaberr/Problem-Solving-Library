// Codeforces : https://codeforces.com/contest/1036/problem/C
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
#define By int t = 1;cin >> t;
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

int l , r;
string s;
int dp[25][2][4];

int idk(int i , bool mx , int non) {
    if(i == s.size())
        return (non <= 3);
    if(non > 3)
        return 0;
    int &ret = dp[i][mx][non];
    if(~ret)
        return ret;
    int end = mx ? s[i] - '0' : 9;
    ret = 0;
    for (int j = 0; j <= end; ++j) {
        ret += idk(i + 1 , mx && j == end , non + (j > 0));
    }
    return ret;
}

void solve() {
    cin >> l >> r;
    init;
    s = to_string(r);
    int ans = idk(0 , 1 , 0);
    s = to_string(l - 1);
    init;
    ans -= idk(0 , 1 , 0);
    cout << ans << endl;
}

int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}
// الحمدلله رب العالمين