// Codeforces : https://codeforces.com/contest/687/problem/C
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
#define init memset(dp , -1 , sizeof dp) // Note : use it with 0 , -1 only (because it fills each "byte" `not the whole int` with 0x0 ansing a 0 or 0xFF ansing -1) AND it make it in O(N) if you use vector use std::fill instead

void Free_Palestine() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

vector<int> h;
int k , n;
vector<vector<bool>> dp;
bool mem[505][505][505];
set<int> ans;

void idk(int i , int s , int x) {
    if (s == k) {
        dp[s][x] = true;
        ans.insert(x);
        return;
    }
    if (i == n || s > k)
        return;
    if(mem[i][s][x])
        return;
    mem[i][s][x] = 1;
    idk(i + 1 , s + h[i] , x);
    idk(i + 1 , s + h[i] , x + h[i]);
    idk(i + 1 , s , x);
}

void solve() {
    cin >> n >> k;
    h.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    dp.assign(k + 1 , vector<bool> (k + 1 , false));
    memset(mem , false , sizeof mem);
    dp[0][0] = true;
    idk(0 , 0 , 0);
    cout << ans.size() << endl;
    for (auto x : ans) {
        cout << x << ' ';
    }
}

int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}
// الحمدلله رب العالمين