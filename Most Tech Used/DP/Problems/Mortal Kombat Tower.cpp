// Codeforces : https://codeforces.com/contest/1418/problem/C
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
#define init memset(dp , -1 , sizeof dp) // Note : use it with 0 , -1 only (because it fills each "byte" `not the whole int` with 0x0 ansing a 0 or 0xFF ansing -1) AND it make it in O(N) if you use vector use std::fill instead

void Free_Palestine() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int n;
int h[200005] , dp[200005][2];

int idk(int i , bool prev) {
    if (i >= n)
        return 0;
    int &ret = dp[i][prev];
    if(~ret)
        return ret;
    if(prev == 0) {
        int ch1 = idk(i + 1 , 1) + h[i];
        int ch2 = INT_MAX;
        if (i + 1 < n)
            ch2 = idk(i + 2 , 1) + h[i] + h[i + 1];
        ret = min(ch1 , ch2);
    }
    else
        ret = min(idk(i + 1 , 0) , idk(i + 2 , 0));
    return ret;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
        dp[i][0] = -1;
        dp[i][1] = -1;
    }
    h[n] = 0;
    h[n + 1] = 0;
    cout << idk(0 , 0) << endl;
}

int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}
// الحمدلله رب العالمين