// Codeforces : https://codeforces.com/contest/1195/problem/C
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
#define Code cin.tie(nullptr); cout.tie(nullptr);
#define By int t = 1;//cin >> t;
#define Hossam while(t--) { solve(); }
#define all(x) begin(x), end(x)
#define NO cout << "NO" << endl
#define YES cout << "YES" << endl
#define init memset(dp, -1, sizeof dp)

void Free_Palestine() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

const int MOD = 1e9 + 7;
int n;
vector<int> a , b;
int dp[1000005][3];

int idk(int i , int dir) {
    // base case
    if(i == n)
        return 0;
    // rec
    int &ret = dp[i][dir];
    if(~ret)
        return ret;
    int ch1 = INT_MIN , ch2 = INT_MIN , ch3 = INT_MIN;
    if (dir != 0)
        ch1 = idk(i + 1 , 0) + b[i];
    if (dir != 1)
        ch2 = idk(i + 1 , 1) + a[i];
    ch3 = idk(i + 1 , 2);
    return ret = max({ch1 , ch2 , ch3});
}

void solve() {
    cin >> n;
    init;
    a.resize(n);
    b.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    cout << idk(0 , 2);
}

int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}
// الحمدلله رب العالمين