// Codeforces : https://codeforces.com/gym/101502/problem/L
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
#define all(x) begin(x) , end(x)
#define NO cout << "No" << endl
#define YES cout << "Yes" << endl
#define init memset(dp , -1 , sizeof dp) // Note : Never use it with N = 2 * 1e5 !!! && use it with 0 , -1 only (because it fills each "byte" `not the whole int` with 0x0 ansing a 0 or 0xFF ansing -1) AND it make it in O(N) if you use vector use std::fill instead

void Free_Palestine() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

const int N = 25005 , M = 30;

int n , m , h[N][M] , o[N][M];
pair<int , int> dp[N][M][3];

pair<int , int>  idk(int i , int j , int hossam) {
    if(i == n)
        return {0 , 0};
    pair<int , int> &ret = dp[i][j][hossam];
    if(~ret.first)
        return ret;
    pair<int , int> ch1 = idk(i + 1 , j , 0) , ch2 = {1e18 , 1e18} , ch3 = {1e18 , 1e18};
    ch1.first += h[i][j];
    if(hossam == 0 && j > 0 || hossam == 2 && j > 0) {
        ch2 = idk(i , j - 1 , 2);
        ch2.second += o[i][j - 1];
    }
    if(hossam == 0 && j + 1 < m || hossam == 1 && j + 1 < m) {
        ch3 = idk(i , j + 1 , 1);
        ch3.second += o[i][j];
    }
    return ret = min({ch1 , ch2 , ch3});
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> h[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m - 1; ++j) {
            cin >> o[i][j];
        }
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            for (int k = 0; k <= 2; ++k) {
                dp[i][j][k] = {-1 , -1};
            }
        }
    }
    cout << idk(0 , 0 , 0).first << ' ' << idk(0 , 0 , 0).second << endl;
}

int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}

// الحمدلله رب العالمين