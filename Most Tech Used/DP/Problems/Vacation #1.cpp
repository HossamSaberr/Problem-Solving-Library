// atcoder : https://atcoder.jp/contests/dp/tasks/dp_c
/*
بسم الله الرحمن الرحيم

الْحَمْدُ لِلّهِ الَّذِي هَدَانَا لِهَـذَا وَمَا كُنَّا لِنَهْتَدِيَ لَوْلا أَنْ هَدَانَا اللّهُ

اللهم حرر فلسطين من كيد الصهاينة واجعل كيدهم في نحورهم
اللهم انصر الأقصى والقدس وأهالي غزة وفلسطين اللهم اطمس على أعداء الدين والمدنسين
*/

#include <bits/stdc++.h>

using namespace std;

const long double pii = 3.1415926536;
#define endl '\n'
#define Shity ios_base::sync_with_stdio(false);
#define Code cin.tie(nullptr);cout.tie(nullptr);
#define By int t = 1;//cin >> t;
#define Hossam while(t--) { solve(); }
#define all(x) begin(x), end(x)
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
const int N = 1e5 + 5;
int dp[N][3];
int a[N] , b[N] , c[N];

int idk(int i , int prev) {
    if(i >= n)
        return 0;
    int &ret = dp[i][prev];
    if(~ret)
        return ret;
    int ch1 = 0 , ch2 = 0;
    if(prev == 0) {
        ch1 = idk(i + 1 , 1) + b[i];
        ch2 = idk(i + 1 , 2) + c[i];
    }
    if(prev == 1) {
        ch1 = idk(i + 1 , 0) + a[i];
        ch2 = idk(i + 1 , 2) + c[i];
    }
    if(prev == 2) {
        ch1 = idk(i + 1 , 1) + b[i];
        ch2 = idk(i + 1 , 0) + a[i];
    }
    return ret = max(ch1 , ch2);
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        cin >> b[i];
        cin >> c[i];
    }
    init;
    cout << max({idk(0 , 0) , idk(0 , 1) , idk(0 , 2)}) << endl;
}

int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}
// الحمدلله رب العالمين
