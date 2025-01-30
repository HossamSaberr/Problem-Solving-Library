// Codeforces : https://codeforces.com/gym/105408/problem/J
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
#define init memset(dp , -1 , sizeof dp) // Note : Never use it with N = 2 * 1e5 !!! && use it with 0 , -1 only (because it fills each "byte" `not the whole int` with 0x0 ansing a 0 or 0xFF ansing -1) AND it make it in O(N) if you use vector use std::fill instead

void Free_Palestine() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

string s;
int n , dp[10005][10005];
const int MOD = 1e9 + 7;

int idk(int l , int r , int koshi , int shika) {
    if (l >= r)
        return (s[l] == '1' || koshi < shika) ? 1 : 0;
    int &ret = dp[l][r];
    if(~ret)
        return ret;
    ret = 0;
    if(s[l] == '1')
        ret += idk(l + 1 , r , koshi , shika + 1);
    if(s[r] == '1')
        ret += idk(l , r - 1 , koshi , shika + 1);
    if(s[l] == '0')
        if(koshi < shika)
            ret += idk(l + 1 , r , koshi + 1 , shika);
    if(s[r] == '0')
        if(koshi < shika)
            ret += idk(l , r - 1 , koshi + 1 , shika);
    ret %= MOD;
    return ret;
}

void solve() {
    cin >> n >> s;
    init;
    if(idk(0 , n - 1 , 0 , 0) == 0)
        cout << 0 << endl;
    else
        cout << ((idk(0 , n - 1 , 0 , 0) + 1) % MOD) << endl;
}

int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}

// الحمدلله رب العالمين