// Codeforces : https://codeforces.com/contest/204/problem/A
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

string s;
int l , r , dp[20][2][20][20];

int idk(int i , bool mx , int first , int last) {
    if(i == s.size())
        return (last == first);
    int &ret = dp[i][mx][first][last];
    if(~ret)
        return ret;
    ret = 0;
    int end = mx ? s[i] - '0' : 9;
    for (int j = 0; j <= end; ++j) {
        if(first == 15 && !j)
            ret += idk(i + 1 , mx && (j == end) , first , last);
        else
            ret += idk(i + 1 , mx && (j == end) , (first == 15 ? j : first) , j);
    }
    return ret;
}

void solve() {
    cin >> l >> r;
    init;
    s = to_string(r);
    int ans = idk(0 , 1 , 15 , 15);
    init;
    s = to_string(l - 1);
    ans -= idk(0 , 1 , 15 , 15);
    cout << ans << endl;
}

int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}

// الحمدلله رب العالمين