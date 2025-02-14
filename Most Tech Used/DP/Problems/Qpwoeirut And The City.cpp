// Codeforces : https://codeforces.com/problemset/problem/1706/C
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
#define NO cout << "NO" << endl
#define YES cout << "YES" << endl
#define init memset(dp , -1 , sizeof dp) // Note : Never use it with N = 2 * 1e5 !!! && use it with 0 , -1 only (because it fills each "byte" `not the whole int` with 0x0 ansing a 0 or 0xFF ansing -1) AND it make it in O(N) if you use vector use std::fill instead

void Free_Palestine() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

const int N = 2005;
int n;
vector<int> dp , h;

int idk(int i) {
    if(i >= n - 1)
        return 0;
    int &ret = dp[i];
    if(~ret)
        return ret;
    int g = 0;
    if (h[i] <= h[i - 1] && h[i] <= h[i + 1])
        g = max(h[i - 1], h[i + 1]) - h[i] + 1;
    else if (h[i] <= h[i - 1])
        g = h[i - 1] - h[i] + 1;
    else if (h[i] <= h[i + 1])
        g = h[i + 1] - h[i] + 1;
    int ch1 = g + idk(i + 2) , ch2 = 1e17;
    if ((i - 1) % 2 == 0)
        ch2 = idk(i + 1);
    return ret = min(ch1 , ch2);
}

void solve() {
    cin >> n;
    h.resize(n);
    dp.assign(n + 1 , -1);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    if(n & 1) {
        int ans = 0;
        for (int i = 1; i < n - 1; i += 2) {
            if (h[i] <= h[i - 1] && h[i] <= h[i + 1])
                ans += max(h[i - 1], h[i + 1]) - h[i] + 1;
            else if (h[i] <= h[i - 1])
                ans += h[i - 1] - h[i] + 1;
            else if (h[i] <= h[i + 1])
                ans += h[i + 1] - h[i] + 1;
        }
        return void(cout << ans << endl);
    }
    cout << idk(1) << endl;
}

int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}

// الحمدلله رب العالمين