// Codeforces : https://codeforces.com/gym/101502/problem/D
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
#define all(x) begin(x) , end(x)
#define NO cout << "No" << endl
#define YES cout << "Yes" << endl
#define init memset(dp , -1 , sizeof dp) // Note : Never use it with N = 2 * 1e5 !!! && use it with 0 , -1 only (because it fills each "byte" `not the whole int` with 0x0 ansing a 0 or 0xFF ansing -1) AND it make it in O(N) if you use vector use std::fill instead

void Free_Palestine() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

const int N = 1e4 + 5;

int n , dp[N][10];

int idk(int i , int prev) {
    if(i == n)
        return 0;
    if(i > n)
        return 1e8;
    int &ret = dp[i][prev];
    if(~ret)
        return ret;
    int ans = 1e8;
    for (int j = 1; j <= 6; ++j) {
        if(j == prev)
            continue;
        if(j != 7 - prev)
            ans = min(ans , 1 + idk(i + j , j));
    }
    return ret = ans;
}

void solve() {
    cin >> n;
    init;
    if(idk(0 , 1) >= 1e8)
        cout << -1 << endl;
    else
        cout << idk(0 , 1) << endl;
}

int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}

// الحمدلله رب العالمين