// atcoder : https://atcoder.jp/contests/dp/tasks/dp_k
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
#define init memset(dp , false , sizeof dp) // Note : Never use it with N = 2 * 1e5 !!! && use it with 0 , -1 only (because it fills each "byte" `not the whole int` with 0x0 ansing a 0 or 0xFF ansing -1) AND it make it in O(N) if you use vector use std::fill instead

void Free_Palestine() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}


void solve() {
    int n , k;
    bool dp[110000] {0};
    cin >> n >> k;
    int h[n];
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
        dp[h[i]] = 1;
    }
    for (int i = 1; i <= k; ++i) {
        for(auto x : h)
            if(i - x >= 0 && dp[i - x] == 0)
                dp[i] = 1;
    }
    cout << (dp[k] ? "First" : "Second") << endl;
}

int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}
// الحمدلله رب العالمين