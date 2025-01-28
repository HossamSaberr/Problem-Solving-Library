// Codeforces : https://codeforces.com/contest/1660/problem/C
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

string s;
vector<vector<int>> dp;

int idk(int i , char ch) {
    if(i == s.size())
        return (ch == '!' ? 0 : 1e17);
    int &ret = dp[i][ch];
    if(~ret)
        return ret;
    int ch1 = 1e17 , ch2 = 1e17;
    if(ch == '!') {
        ch1 = idk(i + 1 , '!') + 1;
        ch2 = idk(i + 1 , s[i]);
    }
    else {
        if(ch == s[i])
            ch1 = idk(i + 1 , '!');
        else
            ch2 = 1 + idk(i + 1 , ch);
    }
    return ret = min(ch1 , ch2);
}

void solve() {
    cin >> s;
    dp.assign(s.size() + 1, vector<int>(128, -1));
    cout << idk(0 , '!') << endl;
}

int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}

// الحمدلله رب العالمين