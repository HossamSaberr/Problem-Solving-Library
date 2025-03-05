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
const int N = 3050 , MOD = 1e9 + 7;

void Free_Palestine() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

string s , tt;
int n , m , dp[N][N] , check[N][N];

int idk(int i , int j) {
    if(i >= n || j >= m)
        return 0;
    int &ret = dp[i][j];
    if(~ret)
        return ret;
    ret = max(idk(i + 1 , j) , idk(i , j + 1));
    if(s[i] == tt[j]) {
        if(ret < idk(i + 1 , j + 1) + 1) {
            ret = idk(i + 1 , j + 1) + 1;
            check[i][j] = 1;
        }
    }
    return ret;
}

void build(int i , int j) {
    if(i >= n || j >= m)
        return;
    if(check[i][j]) {
        cout << s[i];
        build(i + 1 , j + 1);
        return;
    }
    if(idk(i + 1 , j) > idk(i , j + 1))
        build(i + 1 , j);
    else
        build(i , j + 1);
}

void solve() {
    cin >> s >> tt;
    n = s.size() , m = tt.size();
    init;
    memset(check , 0 , sizeof check);
    idk(0 , 0);
    build(0 , 0);
}

int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}

// الحمدلله رب العالمين