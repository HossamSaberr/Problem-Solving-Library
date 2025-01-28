// Codeforces : https://codeforces.com/contest/628/problem/D
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
#define all(x) rbegin(x), rend(x)
#define NO cout << "No" << endl
#define YES cout << "Yes" << endl
#define init memset(dp , -1 , sizeof dp) // Note : Never use it with N = 2 * 1e5 !!! && use it with 0 , -1 only (because it fills each "byte" `not the whole int` with 0x0 ansing a 0 or 0xFF ansing -1) AND it make it in O(N) if you use vector use std::fill instead

void Free_Palestine() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int m , d;
const int MOD = 1e9 + 7;
string s , l , r;
int dp[2005][2][2005];

int idk(int i , bool mx , int sum) {
    if(i == s.size())
        return ((sum % m) == 0);
    int &ret = dp[i][mx][sum];
    if(~ret)
        return ret;
    ret = 0;
    int end = mx ? s[i] - '0' : 9;
    if(i % 2) {
        if(end < d)
            return 0;
        return ret = idk(i + 1 , mx && (d == end) , ((sum * 10) + d) % m);
    }
    for (int j = 0; j <= end; ++j) {
        if(j == d)
            continue;
        ret += idk(i + 1 , mx && (j == end) , ((sum * 10) + j) % m);
        ret %= MOD;
    }
    return ret;
}

bool check () {
    bool hossam = false;
    int sum = 0;
    for (int i = 0; i < l.size(); ++i) {
        if(i % 2) {
            if (l[i] != (d + '0')) {
                hossam = true;
                break;
            }
        }
        else {
            if(l[i] == (d + '0')) {
                hossam = true;
                break;
            }
        }
        sum = ((sum * 10) + (l[i] - '0'));
        sum %= m;
    }
    if(sum > 0 || hossam)
        return 0;
    return 1;
}

void solve() {
    cin >> m >> d >> l >> r;
    init;
    s = r;
    int ans = idk(0 , 1 , 0);
    init;
    s = l;
    ans -= idk(0 , 1 , 0);
    if(check())
        ans++;
    cout << (ans + MOD) % MOD << endl;
}

int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}
// الحمدلله رب العالمين