// Codeforces : https://codeforces.com/contest/2050/problem/E
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
#define NO cout << "No" << endl
#define YES cout << "Yes" << endl
#define init memset(dp , -1 , sizeof dp) // Note : Never use it with N = 2 * 1e5 !!! && use it with 0 , -1 only (because it fills each "byte" `not the whole int` with 0x0 ansing a 0 or 0xFF ansing -1) AND it make it in O(N) if you use vector use std::fill instead

void Free_Palestine() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

string a , b , c;
int n , m , k;
const int N = 1e3 + 5;
int dp[N][N];

int idk(int i , int j , int x) {
    if(x == k)
        return 0;
    int &ret = dp[i][j];
    if(~ret)
        return ret;
    int ch1 = 1e17 , ch2 = 1e17;
    if(i < n)
        ch1 = idk(i + 1 , j , x + 1) + (a[i] != c[x]);
    if(j < m)
        ch2 = idk(i , j + 1 , x + 1) + (b[j] != c[x]);
    return ret = min(ch1 , ch2);
}

void solve() {
    cin >> a >> b >> c;
    n = a.size() , m = b.size() , k = c.size();
    init;
    cout << idk(0 , 0 , 0) << endl;
}

int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}
// الحمدلله رب العالمين