// Codeforces : https://codeforces.com/problemset/problem/990/D
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
#define init memset(dp , -1 , sizeof dp) // Note : Never use it with N = 2 * 1e5 !!! && use it with 0 , -1 only (because it fills each "byte" `not the whole int` with 0x0 ansing a 0 or 0xFF ansing -1) AND it make it in O(N) if you use vector use std::fill instead

void Free_Palestine() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
 
    if ((a == 1 && b == 1 && n < 4) || (a != 1 && b != 1)) {
        if(n == 1) {
            YES;
            cout << 0 << endl;
        }
        else
            NO;
        return;
    }
    int cnt = n - max(a, b);
    vector<vector<int>> g(n, vector<int> (n));
    for (int i = 0; i < cnt; i++) {
        g[i + 1][i] = g[i][i + 1] = 1;
    }
    YES;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
        if (i == j) cout << 0;
        else if (b > a) cout << (g[i][j] ? 0 : 1);
        else cout << g[i][j];
        }
        cout << endl;
    }
}


int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}

// الحمدلله رب العالمين