// Codeforces : https://codeforces.com/contest/296/problem/B
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
#define NO cout << "No" << endl
#define YES cout << "Yes" << endl
#define init memset(dp , -1 , sizeof dp) // Note : Never use it with N = 2 * 1e5 !!! && use it with 0 , -1 only (because it fills each "byte" `not the whole int` with 0x0 ansing a 0 or 0xFF ansing -1) AND it make it in O(N) if you use vector use std::fill instead

void Free_Palestine() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

const int MOD = 1e9 + 7 , N = 1e5 + 5;
string s , w;
int n , dp[N][2][2];

int idk(int i , bool c1 , bool c2) {
    if(i == n)
        return (c1 && c2);
    int &ret = dp[i][c1][c2];
    if(~ret)
        return ret;
    ret = 0;
    if(s[i] != '?' && w[i] != '?')
        ret += idk(i + 1 , c1 || (s[i] > w[i]) , c2 || (s[i] < w[i]));
    else if(s[i] == '?' && w[i] != '?') {
        for (int j = 0; j <= 9; ++j) {
            ret += idk(i + 1 , c1 || (j > w[i] - '0') , c2 || (j < w[i] - '0'));
            ret %= MOD;
        }
    }
    else if(s[i] != '?' && w[i] == '?') {
        for (int j = 0; j <= 9; ++j) {
            ret += idk(i + 1 , c1 || (s[i] - '0' > j) , c2 || (s[i] - '0' < j));
            ret %= MOD;
        }
    }
    else {
        for (int j = 0; j <= 9; ++j) {
            for (int k = 0; k <= 9; ++k) {
                ret += idk(i + 1 , c1 || (j > k) , c2 || (j < k));
                ret %= MOD;
            }
        }
    }
    return ret;
}

void solve() {
    cin >> n >> s >> w;
    init;
    cout << (idk(0 , 0 , 0) % MOD) << endl;
}

int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}

// الحمدلله رب العالمين