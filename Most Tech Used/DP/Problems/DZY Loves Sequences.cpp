// Codeforces : https://codeforces.com/contest/446/problem/A
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

const int N = 1e5 + 5;
int n, h[N];
unordered_map<int, int> dp[N][2];

int idk(int i, bool flag, int prev) {
    if (i >= n)
        return 0;
    if (dp[i][flag].count(prev))
        return dp[i][flag][prev];
    int ret = 0;
    if (flag) {
        if (h[i] > prev) 
            ret = 1 + idk(i + 1, 1, h[i]);
    }
    else {
        if (h[i] > prev) 
            ret = 1 + idk(i + 1, 0, h[i]);
        ret = max(ret, 1 + idk(i + 1, 1, prev + 1));
        if (i + 1 < n && h[i + 1] > prev) 
            ret = max(ret, 1 + idk(i + 1, 1, prev + 1));
    }

    return dp[i][flag][prev] = ret;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
        dp[i][0].clear();
        dp[i][1].clear();
    }
    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    int ans = 1;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, 1 + idk(i + 1, 0, h[i]));
        if (i + 1 < n) 
            ans = max(ans, 1 + idk(i + 1, 1, h[i + 1] - 1));
    }

    cout << ans << endl;
}


int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}
// الحمدلله رب العالمين