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

const int N = 2e5 + 5 , MOD = 1e9 + 7;
const int dx[] = {0, 0, 1, -1, -1, 1, -1, 1};
const int dy[] = {1, -1, 0, 0, 1, 1, -1, -1};
const char dir[] = {'R', 'L', 'D', 'U'};
int add(int x, int a) { return ((a % MOD) + (x % MOD)) % MOD; }
int mul(int a, int b) { return ((a % MOD) * (b % MOD)) % MOD; }
int sub(int a, int b) { return ((a % MOD) - (b % MOD) + MOD) % MOD; }
int binpow(int x,int y,int m = MOD){x%=m;int ans=1;while(y>0){if(y&1)ans=((ans%m)*(x%m))%m;x=((x%m)*(x%m))%m;y/=2;}return ans;}
int gcd(int a , int b) {if(b == 0) return a; return gcd(b , a % b);}

void Free_Palestine() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

string s;
int n , dp[N];
vector<int> cnt[30];

int idk(int i) {
    if(i >= n)
        return 0;
    int &ret = dp[i];
    if(~ret)
        return ret;
    ret = 1e9;
    for (int j = 0; j < 26; ++j) {
        auto it = upper_bound(all(cnt[j]) , i);
        // first ==> cnt[j].end()
        // idx
        int idx;
        if(it == cnt[j].end())
            idx = n + 1;
        else
            idx = *it;
        ret = min(ret , idk(idx) + 1);
    }
    return ret;
}

void build(int i) {
    if(i >= n)
        return;
    for (int j = 0; j < 26; ++j) {
        auto it = upper_bound(all(cnt[j]) , i);
        // first ==> cnt[j].end()
        // idx
        int idx;
        if(it == cnt[j].end())
            idx = n + 1;
        else
            idx = *it;
        if(dp[i] == idk(idx) + 1) {
            cout << (char)(j + 'a');
            build(idx);
            return;
        }
    }
}

void solve() {
    cin >> s;
    s = '@' + s;
    n = s.size();
    for (int i = 1; i < n; ++i) {
        cnt[s[i] - 'a'].push_back(i);
    }
    init;
    idk(0);
    build(0);
}

int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}

// الحمدلله رب العالمين