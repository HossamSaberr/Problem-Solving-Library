// UVA : https://vjudge.net/problem/UVA-10739
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
#define init memset(dp , -1 , sizeof dp) // Note : use it with 0 , -1 only (because it fills each "byte" `not the whole int` with 0x0 resulting a 0 or 0xFF resulting -1) AND it make it in O(N) if you use vector use std::fill instead

void Free_Palestine() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

string s;
int n;
int dp[1005][1005];

int idk(int l , int r) {
    if(l >= r)
        return 0;
    int &ret = dp[l][r];
    if(~ret)
        return ret;
    int ch1 = 1e17 , ch2 = 1e17 , ch3 = 1e17;
    if(s[l] == s[r]) {
        ch1 = idk(l + 1 , r - 1);
    }
    else {
        ch1 = idk(l + 1 , r - 1) + 1;
        ch2 = idk(l + 1 , r) + 1;
        ch3 = idk(l , r - 1) + 1;
    }
    return ret = min({ch1 , ch2 , ch3});
}

void solve() {
    cin >> s;
    n = s.size();
    init;
    cout << idk(0 , n - 1) << endl;
}

int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}
// الحمدلله رب العالمين
