// POJ : https://vjudge.net/problem/POJ-1260
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

int n;
int h[105] , c[105] , sum[105];
int dp[105][105];

int idk(int l , int r) {
    if(n - 1 == r)
        return (sum[r] - (l > 0 ? sum[l - 1] : 0) + 10) * c[r];
    int &ret = dp[l][r];
    if(~ret)
        return ret;
    int ch1 = idk(l , r + 1);
    int ch2 = idk(r + 1 , r + 1) + (sum[r] - (l > 0 ? sum[l - 1] : 0) + 10) * c[r];
    return ret = min(ch1 , ch2);
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> h[i] >> c[i];
    }
    sum[0] = h[0];
    for (int i = 1; i < n; ++i) {
        sum[i] = sum[i - 1] + h[i];
    }
    init;
    if (n < 2) {
        cout << 0 << endl;
        return;
    }
    cout << idk(0 , 0) << endl;
}

int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}
// الحمدلله رب العالمين
