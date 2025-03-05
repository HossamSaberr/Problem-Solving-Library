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
#define all(x) begin(x) , end(x)
#define NO cout << "NO" << endl
#define YES cout << "YES" << endl
#define init memset(dp , -1 , sizeof dp) // Note : Never use it with N = 2 * 1e5 !!! && use it with 0 , -1 only (because it fills each "byte" `not the whole int` with 0x0 ansing a 0 or 0xFF ansing -1) AND it make it in O(N) if you use vector use std::fill instead

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const char dir[] = {'U', 'D', 'L', 'R'};
const int N = 1e5 + 5 , MOD = 1e9 + 7;

void Free_Palestine() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int n , h[N] , dp[N]; /// dp[i] ==> lIS until i
int idk(int i) {
    if(i == n)
        return 0;
    int &ret = dp[i];
    if(~ret)
        return ret;
    ret = 1;
    for(int j = i + 1; j < n; ++j) {
        if(h[j] > h[i]) {
            ret = max(ret, 1 + idk(j));
        }
    }
    return ret;
}

vector<bool> vis(N , 0);

void build(int i) {
    if (i == n)
        return;
    cout << h[i] << ' ';
    int nextIdx = -1;
    for (int j = i + 1; j < n; ++j) {
        if (h[j] > h[i] && dp[i] == dp[j] + 1 && !vis[j]) {
            if (nextIdx == -1 || h[j] < h[nextIdx]) {
                nextIdx = j;
            }
        }
    }
    if (nextIdx != -1) {
        vis[nextIdx] = 1;
        build(nextIdx);
    }
}

void solve() {
    while(cin >> n && n) {
        for (int i = 0; i < n; ++i) {
            cin >> h[i];
        }
        init;
        vis.assign(N , 0);
        int ans = 0, idx = -1;
        for (int i = 0; i < n; ++i) {
            if (ans <= idk(i)) {
                ans = idk(i);
                idx = i;
            }
        }
        cout << ans << ' ';
        build(idx);
        cout << endl;
    }
}

int32_t main() {
//    Free_Palestine();
    Shity Code By Hossam
    return 0;
}

// الحمدلله رب العالمين