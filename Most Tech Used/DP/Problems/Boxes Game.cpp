// Codeforces : https://codeforces.com/gym/101502/problem/J
/*
بسم الله الرحمن الرحيم

الْحَمْدُ لِلّهِ الَّذِي هَدَانَا لِهَـذَا وَمَا كُنَّا لِنَهْتَدِيَ لَوْلا أَنْ هَدَانَا اللّهُ

اللهم حرر فلسطين من كيد الصهاينة واجعل كيدهم في نحورهم
اللهم انصر الأقصى والقدس وأهالي غزة وفلسطين اللهم اطمس على أعداء الدين والمدنسين
*/

#include <bits/stdc++.h>

using namespace std;

const long double pii = 3.1415926536;
//#define int long long
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

const int N = 1001;

int n , h[N] , dp[N][N][2];
bool vis[N][N][2];

int idk(int l , int r , bool hossam) {
    if(l > r)
        return 0;
    int &ret = dp[l][r][hossam];
    if(vis[l][r][hossam])
        return ret;
    vis[l][r][hossam] = 1;
    int ch1 , ch2;
    if(hossam) {
        ch1 = idk(l + 1 , r , 0);
        ch2 = idk(l , r - 1 , 0);
        return ret = min(ch1 , ch2);
    }
    else {
        ch1 = idk(l + 1 , r , 1) + h[l];
        ch2 = idk(l , r - 1 , 1) + h[r];
        return ret = max(ch1 , ch2);
    }
}

void solve() {
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
        sum += h[i];
    }
    memset(vis , 0 , sizeof vis);
    int x = idk(0 , n - 1 , 0);
    int y = sum - x;
    cout << x - y << endl;
}

int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}

// الحمدلله رب العالمين