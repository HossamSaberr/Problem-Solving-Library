// Codeforces : https://codeforces.com/problemset/gymProblem/104678/B
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
#define Code cin.tie(nullptr); cout.tie(nullptr);
#define By int t = 1;//cin >> t;
#define Hossam while(t--) { solve(); }
#define all(x) begin(x), end(x)
#define NO cout << "NO" << endl
#define YES cout << "YES" << endl

void Free_Palestine() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

const int N = 2e5 + 5;

int n , k;
vector<vector<int>> h;
int dp[N];

int idk(int i) {
    // base case
    if(i > n)
        return 0;
    // rec
    int &ret = dp[i];
    if(~ret)
        return dp[i];
    ret = idk(i + 1);
    for(auto it : h[i])
        ret = max(ret , idk(it) + 1);
    return ret;
}

void solve() {
    cin >> n >> k;
    memset(dp , -1 , sizeof dp);
    h.resize(n + 1);
    while (k--) {
        int a , b;
        cin >> a >> b;
        h[a].push_back(b);
    }
    cout << idk(1) << endl;
}

int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}
// الحمدلله رب العالمين