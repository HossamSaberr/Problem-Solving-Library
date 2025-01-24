// Codeforces : https://codeforces.com/contest/999/problem/F
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
#define NO cout << "NO" << endl
#define YES cout << "YES" << endl
#define init memset(dp , -1 , sizeof dp) // Note : Never use it with N = 2 * 1e5 !!! && use it with 0 , -1 only (because it fills each "byte" `not the whole int` with 0x0 ansing a 0 or 0xFF ansing -1) AND it make it in O(N) if you use vector use std::fill instead

void Free_Palestine() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int n , k;
vector<int> c , f , h;
map<int, int> freq , fav;
int dp[505][5005];

int idk(int i , int use , int pl , int freqq) {
    if(i >= fav[pl] || freqq <= use)
        return 0;
    int &ret = dp[i][use];
    if(~ret)
        return ret;
    ret = INT_MIN;
    for (int j = 1; j <= min(freqq - use , k); ++j) {
        ret = max(ret , idk(i + 1 , use + j , pl , freqq) + h[j - 1]);
    }
    return ret;
}

void solve() {
    cin >> n >> k;
    c.resize(n * k);
    f.resize(n);
    h.resize(k);
    for (int i = 0; i < n * k; ++i) {
        cin >> c[i];
        freq[c[i]]++;
    }
    for (int i = 0; i < n; ++i) {
        cin >> f[i];
        fav[f[i]]++;
    }
    for (int i = 0; i < k; ++i) {
        cin >> h[i];
    }
    int ans = 0;
    for (auto it : fav) {
        if (freq[it.first] == 0)
            continue;
        init;
        ans += idk(0 , 0 , it.first , freq[it.first]);
    }
    cout << ans << endl;
}

int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}
// الحمدلله رب العالمين