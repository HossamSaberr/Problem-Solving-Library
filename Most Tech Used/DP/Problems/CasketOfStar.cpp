// topcoder : https://vjudge.net/problem/TopCoder-11781

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

int n;
int dp[55][55];
int h[55];

int idk(int l , int r) {
    if (l + 1 >= r)
        return 0;
    int &ret = dp[l][r];
    if(~ret)
        return ret;
    ret = 0;
    for (int i = l + 1; i < r; ++i) {
        ret = max(ret , idk(i , r) + idk(l , i) + h[l] * h[r]);
    }
    return ret;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    init;
    cout << idk(0 , n - 1) << endl;
}

int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}
// الحمدلله رب العالمين
