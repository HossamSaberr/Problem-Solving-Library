// Codeforces : https://codeforces.com/problemset/problem/1354/B
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
#define ll long long
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

const int N = 200005;

string s;
int n , dp[N][2][2][2] , vis[N][2][2][2] , c = 0;


int idk(int i , bool one , bool two , bool three) {
    if(one && two && three)
        return 0;
    if(i == n)
        return 1e18;
    int &ret = dp[i][one][two][three];
    if(vis[i][one][two][three] == c)
        return ret;
    vis[i][one][two][three] = c;
    int ch1 = 1e18 , ch2 = 1e18 , ch3 = 1e18 , ch4 = 1e18;
    if(!one && !two && !three)
        ch1 = idk(i + 1 , one , two , three);
    if (s[i] == '1')
        ch2 = idk(i + 1 , 1 , two , three) + 1;
    if (s[i] == '2')
        ch3 = idk(i + 1 , one , 1 , three) + 1;
    if (s[i] == '3')
        ch4 = idk(i + 1 , one , two , 1) + 1;
    return ret = min({ch1 , ch2 , ch3 , ch4});
}

void solve() {
    ++c;
    cin >> s;
    n = s.size();
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                for (int l = 0; l < 2; ++l) {
                    vis[i][j][k][l] = 0;
                }
            }
        }
    }
    int ans = idk(0 , 0 , 0 , 0);
    if(ans == 1e18)
        ans = 0;
    cout << ans << endl;
}

int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}

// الحمدلله رب العالمين