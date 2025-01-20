// Codeforces : https://codeforces.com/problemset/problem/1881/E
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
#define init memset(dp , -1 , sizeof dp)

void Free_Palestine() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

const int N = 2e5 + 5;

int dp[N];
int n;
vector<int> h;

int idk(int i) {
    // base case
    if(i > n)
        return 1e5;
    if(i == n)
        return 0;
    // rec
    int &ret = dp[i];
    if(~ret)
        return ret;
    int take = 1e9;
    if(i + h[i] + 1 <= n)
        take = idk(i + h[i] + 1);
    int nooo = idk(i + 1) + 1;
    return ret = min(take , nooo);
}

void solve() {
    cin >> n;
    h.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    init;
    cout << idk(0) << endl;
}

int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}
// الحمدلله رب العالمين