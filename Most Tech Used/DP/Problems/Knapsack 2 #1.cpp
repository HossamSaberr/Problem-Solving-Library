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

int n , w;
const int N = 105 , NN = 100 * 1e3 + 5;
int we[N] , val[N] , dp[N][NN];

int idk(int i , int currval) {
    if(i == n)
        return (currval == 0 ? 0 : 1e9);
    int &ret = dp[i][currval];
    if(~ret)
        return ret;
    int ch1 = idk(i + 1 , currval);
    int ch2 = 1e9;
    if (currval >= val[i])
        ch2 = we[i] + idk(i + 1, currval - val[i]);
    return ret = min(ch1 , ch2);
}

void solve() {
    cin >> n >> w;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> we[i] >> val[i];
        sum += val[i];
    }
    init;
    int ans = 0;
    for (int v = sum; v >= 0; --v) {
        if (idk(0, v) <= w) {
            ans = v;
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
