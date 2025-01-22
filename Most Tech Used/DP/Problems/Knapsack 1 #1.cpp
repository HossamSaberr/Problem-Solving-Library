// atcoder : https://atcoder.jp/contests/dp/tasks/dp_d
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
#define init memset(dp , -1 , sizeof dp) // Note : use it with 0 , -1 only (because it fills each "byte" `not the whole int` with 0x0 ansing a 0 or 0xFF ansing -1) AND it make it in O(N) if you use vector use std::fill instead

void Free_Palestine() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int n , w;
const int N = 105 , NN = 1e5 + 5;
int we[N] , val[N] , dp[N][NN];

int idk(int i , int rem) {
    if(i == n)
        return 0;
    int &ret = dp[i][rem];
    if(~ret)
        return ret;
    int ch1 = -1e9;
    if(we[i] + rem <= w)
        ch1 = idk(i + 1 , rem + we[i]) + val[i];
    int ch2 = idk(i + 1 , rem);
    return ret = max(ch1 , ch2);
}

void solve() {
    cin >> n >> w;
    for (int i = 0; i < n; ++i) {
        cin >> we[i] >> val[i];
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
