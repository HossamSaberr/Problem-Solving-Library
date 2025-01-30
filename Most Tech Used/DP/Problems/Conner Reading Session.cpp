// Codeforces : https://codeforces.com/gym/105408/problem/C
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

int n , dp[1005][505];
vector<int> b , p , f;

int idk(int i , int sum , vector<int> h) {
    if(sum > 480) {
        sum -= 480;
        if(sum > 300)
            return -1e17;
        return 0;
    }
    if(i == n)
        return 0;
    int &ret = dp[i][sum];
    if(~ret)
        return ret;
    int ch1 = idk(i + 1 , sum , h); // skip
    int ch2 = 0;
    if(sum <= 480)
        ch2 = h[i] + idk(i + 1 , sum + 3 * b[i] , h); // take
    return ret = max(ch1 , ch2);
}

void solve() {
    cin >> n;
    b.resize(n);
    p.resize(n);
    f.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> f[i];
    }
    init;
    int pp = idk(0 , 0 , p);
    init;
    int ff = idk(0 , 0 , f);
    if(pp > ff)
        cout << "PLEASURE" << endl;
    else if(pp < ff)
        cout << "FAME" << endl;
    else
        cout << "EITHER" << endl;
}

int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}

// الحمدلله رب العالمين