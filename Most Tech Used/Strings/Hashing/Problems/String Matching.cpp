// CSES : https://cses.fi/problemset/task/1753
/*
بسم الله الرحمن الرحيم

الْحَمْدُ لِلّهِ الَّذِي هَدَانَا لِهَـذَا وَمَا كُنَّا لِنَهْتَدِيَ لَوْلا أَنْ هَدَانَا اللّهُ

اللهم حرر فلسطين من كيد الصهاينة واجعل كيدهم في نحورهم
اللهم انصر الأقصى والقدس وأهالي غزة وفلسطين اللهم اطمس على أعداء الدين والمدنسين
*/

#include <bits/stdc++.h>

using namespace std;

const long double pii = 3.1415926536;
//#define int long long
#define endl '\n'
#define Shity ios_base::sync_with_stdio(false);
#define Code cin.tie(nullptr);cout.tie(nullptr);
#define By int t = 1;//cin >> t;
#define Hossam while(t--) { solve(); }
#define all(x) begin(x), end(x)
#define NO cout << "NO" << endl
#define YES cout << "YES" << endl
#define init memset(dp , -1 , sizeof dp) // Note : Never use it with N = 2 * 1e5 !!! && use it with 0 , -1 only (because it fills each "byte" `not the whole int` with 0x0 ansing a 0 or 0xFF ansing -1) AND it make it in O(N) if you use vector use std::fill instead

void Free_Palestine() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

const uint64_t HashMod = (1ULL << 61) - 1;
const uint64_t seed = chrono::system_clock::now().time_since_epoch().count();
const uint64_t base = mt19937_64(seed)() % (HashMod / 3) + (HashMod / 3);
const uint64_t N = 1e6 + 5;
uint64_t p[N] , inv[N] , h[N] , dp[N];

int64_t MUL(uint64_t a, uint64_t b) {
    uint64_t l1 = (uint32_t) a, h1 = a >> 32, l2 = (uint32_t) b, h2 = b >> 32;
    uint64_t l = l1 * l2, m = l1 * h2 + l2 * h1, h = h1 * h2;
    uint64_t ret = (l & HashMod) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
    ret = (ret & HashMod) + (ret >> 61);
    ret = (ret & HashMod) + (ret >> 61);
    return (int64_t) ret - 1;
}

uint64_t binpow(uint64_t a, uint64_t b) {
    a %= HashMod;
    uint64_t res = 1;
    while (b > 0) {
        if (b & 1)
            res = MUL(res , a);
        a = MUL(a , a);
        b >>= 1;
    }
    return res;
}

void pre() {
    p[0] = 1;
    inv[0] = 1;
    for(int i = 1;i < N;i++) {
        p[i] = MUL(p[i - 1] , base);
        inv[i] = binpow(p[i] , HashMod - 2);
    }
}

void gethash(const string& s) {
    dp[0] = s[0];
    for (int i = 1; i < s.size(); ++i) {
        dp[i] = (s[i] + MUL(dp[i - 1], base)) % HashMod;
    }
}

uint64_t get_substring_hash(int l , int r) {
    uint64_t result = dp[r];
    if (l > 0)
        result = (result + HashMod - MUL(dp[l - 1] ,  p[r - l + 1])) % HashMod;
    return result;
}

void solve() {
    pre();
    string s;
    cin >> s;
    string ss;
    cin >> ss;
    gethash(ss);
    uint64_t x = dp[ss.size() - 1];
    gethash(s);
    int ans = 0;
    for (int i = 0; i + ss.size() <= s.size(); ++i) {
        uint64_t xx = get_substring_hash(i , i + ss.size() - 1);
        if(x == xx)
            ans++;
    }
    cout << ans << endl;
}

int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}

// الحمدلله رب العالمين