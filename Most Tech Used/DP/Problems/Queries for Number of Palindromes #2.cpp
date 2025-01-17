// Codeforces : https://codeforces.com/contest/245/problem/H
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
#define init memset(dp , -1 , sizeof dp) // Note : use it with 0 , -1 only (because it fills each "byte" `not the whole int` with 0x0 resulting a 0 or 0xFF resulting -1) AND it make it in O(N) if you use vector use std::fill instead

void Free_Palestine() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

string s;
int n;
int dp[5005][5005];
bool pal[5005][5005];
bool vis[5005][5005];

bool check(int i , int j) {
    if(i >= j)
        return 1;
    bool &ret = pal[i][j];
    if(vis[i][j])
        return ret;
    vis[i][j] = 1;
    return ret = (s[i] == s[j]) && check(i + 1 , j - 1);
}

int idk(int l , int r) {
    if(l > r)
        return 0;
    if (l == r)
        return 1;
    int &ret = dp[l][r];
    if(~ret)
        return ret;
    ret = idk(l + 1 , r) + idk(l , r - 1) - idk(l + 1 , r - 1);
    if(check(l , r))
        ret++;
    return ret;
}

void solve() {
    cin >> s;
    n = s.size();
    init;
    memset(vis , false , sizeof vis);
    memset(pal , false , sizeof pal);
    int q;
    cin >> q;
    while (q--) {
        int l , r;
        cin >> l >> r;
        cout << idk(l - 1 , r - 1) << endl;
    }
}

int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}
// الحمدلله رب العالمين
