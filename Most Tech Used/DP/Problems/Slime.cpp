// Codeforces : https://codeforces.com/contest/1038/problem/D
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

int n , h[500005] , dp[500005][4];

int idk(int i , int j) {
    if(i == n)
        return ((j == 3) ? 0 : -1e17);
    int &ret = dp[i][j];
    if(~ret)
        return ret;
    int ch1 = -1e17 , ch2 = -1e17;
    if(j == 0) {
        ch1 = h[i] + idk(i + 1 , 1);
        ch2 = -h[i] + idk(i + 1 , 2);
    }
    else if(j == 1) {
        ch1 = h[i] + idk(i + 1 , 1);
        ch2 = -h[i] + idk(i + 1 , 3);
    }
    else if(j == 2) {
        ch1 = h[i] + idk(i + 1 , 3);
        ch2 = -h[i] + idk(i + 1 , 2);
    }
    else {
        ch1 = h[i] + idk(i + 1 , 3);
        ch2 = -h[i] + idk(i + 1 , 3);
    }
    return ret = max(ch1 , ch2);
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    if(n == 1)
        return void(cout << h[0] << endl);
    init;
    cout << idk(0 , 0) << endl;
}

int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}

// الحمدلله رب العالمين