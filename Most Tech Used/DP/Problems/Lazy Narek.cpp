// Codeforces : https://codeforces.com/contest/2005/problem/C
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
#define init memset(vis , false , sizeof vis) // Note : Never use it with N = 2 * 1e5 !!! && use it with 0 , -1 only (because it fills each "byte" `not the whole int` with 0x0 ansing a 0 or 0xFF ansing -1) AND it make it in O(N) if you use vector use std::fill instead

void Free_Palestine() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

const int N = 1e3 + 5;
string s = "narek";
int n , m , id = 0;
vector<string> h;
int dp[N][6], vis[N][6];

int idk(int i , int x) {
    if (i == n)
        return -x;
    int &ret = dp[i][x];
    if (vis[i][x] == id)
        return ret;
    vis[i][x] = id;
    ret = idk(i + 1 , x);
    int ans = 0;
    for(auto ch : h[i]) {
        if(s[x] == ch)
            x++;
        else if(s.find(ch) != string::npos)
            ans--;
        if(x == 5) {
            ans += x;
            x = 0;
        }
    }
    return ret = max(ret , ans + idk(i + 1 , x));
}

void solve() {
    ++id;
    cin >> n >> m;
    h.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    cout << idk(0 , 0) << endl;
}
    
int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}

// الحمدلله رب العالمين