// Codeforces : https://codeforces.com/problemset/problem/830/A
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
#define init memset(dp , -1 , sizeof dp)

void Free_Palestine() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int n , k , p;
int a[1002] , b[2002];
int dp[1002][2002];

int idk(int i , int j) {
    if (i == 0)
        return 0;
    if (j == 0)
        return LONG_LONG_MAX;
    int &ret = dp[i][j];
    if (~ret)
        return ret;
    int ch1 = idk(i , j - 1);
    int ch2 = idk(i - 1 , j - 1);
    if (ch2 != LONG_LONG_MAX)
        ch2 = max(ch2 , abs(a[i - 1] - b[j - 1]) + abs(b[j - 1] - p));
    return ret = min(ch1 , ch2);
}

void solve() {
    cin >> n >> k >> p;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < k; ++i) {
        cin >> b[i];
    }
    sort(a , a + n);
    sort(b , b + k);
    init;
    int ans = LONG_LONG_MAX;
    for (int j = n; j <= k; ++j) {
        ans = min(ans , idk(n , j));
    }
    cout << ans << endl;
}

int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}
// الحمدلله رب العالمين