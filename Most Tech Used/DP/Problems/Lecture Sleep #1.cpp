// Codeforces : https://codeforces.com/gym/302977/problem/D

// V1 : Recusive DP
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

int n , k;
const int N = 1e5 + 5;
int h[N] , c[N] , dp[N][2] , pre[N];

int idk(int i , bool flag) {
    if(i >= n)
        return 0;
    int &ret = dp[i][flag];
    if(~ret)
        return ret;
    int ch1 = idk(i + 1, flag) + (c[i] == 1 ? h[i] : 0); // leave
    int ch2 = -1e17;
    if (!flag && i + k <= n)
        ch2 = idk(i + k , 1) + pre[i + k] - pre[i]; // take
    return ret = max(ch1 , ch2);
}

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    pre[0] = 0;
    for (int i = 1; i <= n; ++i) {
        pre[i] = pre[i - 1] + h[i - 1];
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    init;
    cout << idk(0 , 0) << endl;
}

int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}
// الحمدلله رب العالمين
