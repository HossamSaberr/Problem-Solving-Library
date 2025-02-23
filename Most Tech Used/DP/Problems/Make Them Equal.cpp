// Codeforces : https://codeforces.com/problemset/problem/1633/D
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
#define By int t = 1;cin >> t;pre();
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

const int N = 1e3 + 5 , K = N * 15;

int cost[N];

void pre() {
    for (int i = 0; i < N; ++i) {
        cost[i] = 1e9;
    }
    cost[1] = 0;
    for (int i = 1; i < N; ++i) {
        for (int j = 1; j <= i; ++j) {
            if(i + (i / j) < N)
                cost[i + (i / j)] = min(cost[i + (i / j)] , cost[i] + 1);
        }
    }
}
int n , k , h[N] , c[N] , dp[N][K];

int idk(int i , int rem) {
    if(i == n)
        return 0;
    int &ret = dp[i][rem];
    if(~ret)
        return ret;
    int ch1 = idk(i + 1 , rem) , ch2 = -1e18;
    if(rem + cost[h[i]] <= k)
        ch2 = idk(i + 1 , rem + cost[h[i]]) + c[i];
    return ret = max(ch1 , ch2);
}

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
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
