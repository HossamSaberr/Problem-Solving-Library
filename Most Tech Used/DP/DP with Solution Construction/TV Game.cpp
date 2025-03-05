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
#define all(x) begin(x) , end(x)
#define NO cout << "NO" << endl
#define YES cout << "YES" << endl
#define init memset(dp , -1 , sizeof dp) // Note : Never use it with N = 2 * 1e5 !!! && use it with 0 , -1 only (because it fills each "byte" `not the whole int` with 0x0 ansing a 0 or 0xFF ansing -1) AND it make it in O(N) if you use vector use std::fill instead

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const char dir[] = {'U', 'D', 'L', 'R'};
const int N = 30 , MOD = 1e9 + 7;

void Free_Palestine() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int n , dp[N][N] , h[N];
string s;

int idk(int idx , int i , int j) {
    if(i > n || j > n)
        return 0;
    if (idx == 2 * n)
        return 0;
    int &ret = dp[i][j];
    if (~ret)
        return ret;
    int ch1 = 0 ,ch2 = 0;
    if(i < n)
        ch1 = idk(idx + 1 , i + 1 , j) + (s[idx] - '0') * h[n - i - 1];
    if(j < n)
        ch2 = idk(idx + 1 , i , j + 1) + (s[idx] - '0') * h[n - j - 1];
    return ret = max({ch1, ch2});
}

void build(int idx , int i , int j) {
    if(i > n || j > n)
        return;
    if (idx == 2 * n)
        return;
    int ch1 = idk(idx + 1 , i + 1 , j) + (s[idx] - '0') * h[n - i - 1];
    if (i < n && dp[i][j] == ch1) {
        cout << 'H';
        build(idx + 1 , i + 1 , j);
        return;
    }
    cout << 'M';
    build(idx + 1 , i , j + 1);
}

void solve() {
    cin >> n >> s;
    h[0] = 1;
    for (int i = 1; i < n; i++)
        h[i] = h[i - 1] * 10;
    init;
    idk(0 , 0 , 0);
    build(0 , 0 , 0);
}

int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}

// الحمدلله رب العالمين