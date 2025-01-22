// atcoder : https://atcoder.jp/contests/dp/tasks/dp_e
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

void solve() {
    int n , w;
    cin >> n >> w;
    int sum = 0;
    vector<int> we(n + 1 , 0) , val(n + 1 , 0);
    for (int i = 1; i <= n; ++i) {
        cin >> we[i] >> val[i];
        sum += val[i];
    }
    vector<int> dp(sum + 1 , 1e17);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = sum; j >= val[i]; --j) {
            dp[j] = min(dp[j] , dp[j - val[i]] + we[i]);
        }
    }
    int ans = 0;
    for (int j = sum; j >= 0; --j) {
        if (dp[j] <= w) {
            ans = j;
            break;
        }
    }
    cout << ans << endl;
}

int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}
// الحمدلله رب العالمين
