// Codeforces : https://codeforces.com/contest/1133/problem/E
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

int n , k;
vector<int> h;
int dp[5005][5005];

int idk(int l , int r) {
    if(r == 0 || l >= n)
        return 0;
    int &ret = dp[l][r];
    if(~ret)
        return ret;
    int ch1 = idk(l + 1 , r);
    auto it = upper_bound(all(h) , h[l] + 5);
    if(it != h.begin())
        it--;
    int ch2 = idk((it - h.begin()) + 1 , r - 1) + ((it - h.begin()) - l + 1);
    return ret = max(ch1 , ch2);
}

void solve() {
    cin >> n >> k;
    h.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    init;
    sort(all(h));
    cout << idk(0 , k) << endl;
}

int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}
// الحمدلله رب العالمين
