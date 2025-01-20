// CSES : https://cses.fi/problemset/task/1637/
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
#define init memset(dp , INT_MAX , sizeof dp)
 
void Free_Palestine() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
 
const int MOD = 1e9 + 7;
 
void solve() {
    int n;
    cin >> n;
    vector<int> dp(n + 1 , INT_MAX);
    dp[n] = 0;
    for (int i = n; i >= 0; i--) {
        int x = i;
        while (x) {
            int h = x % 10;
            x /= 10;
            dp[i - h] = min(dp[i - h] , dp[i] + 1);
        }
    }
    cout << dp[0];
}
 
int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}
// الحمدلله رب العالمين