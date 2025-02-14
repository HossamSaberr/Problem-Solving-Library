// Codeforces : https://codeforces.com/problemset/problem/633/C
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
#define NO cout << "No" << endl
#define YES cout << "Yes" << endl
#define init memset(dp , -1 , sizeof dp) // Note : Never use it with N = 2 * 1e5 !!! && use it with 0 , -1 only (because it fills each "byte" `not the whole int` with 0x0 ansing a 0 or 0xFF ansing -1) AND it make it in O(N) if you use vector use std::fill instead

void Free_Palestine() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

const uint64_t HashMod = (1ULL << 61) - 1; // 2^61 - 1
const uint64_t seed = chrono::system_clock::now().time_since_epoch().count();
const uint64_t base = mt19937_64(seed)() % (HashMod / 3) + (HashMod / 3);
const int N = 1e4 + 1;

uint64_t base_pow[N];

// Safe modular multiplication function
int64_t MUL(uint64_t a, uint64_t b) {
    uint64_t l1 = (uint32_t) a, h1 = a >> 32, l2 = (uint32_t) b, h2 = b >> 32;
    uint64_t l = l1 * l2, m = l1 * h2 + l2 * h1, h = h1 * h2;
    uint64_t ret = (l & HashMod) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
    ret = (ret & HashMod) + (ret >> 61);
    ret = (ret & HashMod) + (ret >> 61);
    return (int64_t) ret - 1;
}

// Precompute powers of the base
void pre() {
    if (base_pow[0]) return; // Ensure pre() is called only once
    base_pow[0] = 1;
    for (int i = 1; i < N; i++) {
        base_pow[i] = MUL(base_pow[i - 1], base);
    }
}

struct PolyHash {
    vector<int64_t> pref, suf; // Prefix and suffix hashes
    string s;

    PolyHash(const string &str) : s(str) {
        pre(); // Ensure base powers are initialized

        int n = s.size();
        assert(n < N); // Ensure the size is within bounds
        pref.resize(n + 1, 0), suf.resize(n + 1, 0);

        // Compute prefix hashes
        for (int i = 0; i < n; i++) {
            pref[i + 1] = MUL(pref[i], base) + s[i];
            if (pref[i + 1] >= HashMod) pref[i + 1] -= HashMod;
        }

        // Compute suffix hashes
        for (int i = n - 1; i >= 0; i--) {
            suf[i] = MUL(suf[i + 1], base) + s[i];
            if (suf[i] >= HashMod) suf[i] -= HashMod;
        }
    }

    // Update the hash after a character change
    void update(int pos, char ch) {
        int n = s.size();
        s[pos] = ch;

        // Recompute prefix hashes from pos to end
        for (int i = pos; i < n; i++) {
            pref[i + 1] = MUL(pref[i], base) + s[i];
            if (pref[i + 1] >= HashMod) pref[i + 1] -= HashMod;
        }

        // Recompute suffix hashes from pos to start
        for (int i = pos; i >= 0; i--) {
            suf[i] = MUL(suf[i + 1], base) + s[i];
            if (suf[i] >= HashMod) suf[i] -= HashMod;
        }
    }

    // Get hash for substring [l, r] (0-based indexing)
    uint64_t get_hash(int l , int r) {
        int64_t h = pref[r + 1] - MUL(base_pow[r - l + 1], pref[l]);
        return h < 0 ? h + HashMod : h;
    }

    // Get reverse hash for substring [l, r] (0-based indexing)
    uint64_t rev_hash(int l, int r) {
        int64_t h = suf[l] - MUL(base_pow[r - l + 1], suf[r + 1]);
        return h < 0 ? h + HashMod : h;
    }
};

uint64_t pref[N];

uint64_t get_hash(int l, int r) {
    if (l == 0) return pref[r];
    return ((pref[r] - MUL(pref[l - 1], base_pow[r - l + 1])) + HashMod) % HashMod;
}

void solve() {
    int n , m;
    string s;
    cin >> n >> s >> m;
    pref[0] = s[0];
    for (int i = 1; i < n; i++) {
        pref[i] = (MUL(pref[i - 1], base) + s[i]) % HashMod;
    }
    map<uint64_t , string> mp;
    unordered_set<uint64_t> ha;
    for (int i = 0; i < m; ++i) {
        string ss;
        cin >> ss;
        string prevss = ss;
        for(auto &ch : ss)
            ch = tolower(ch);
        PolyHash ph(ss);
        uint64_t ans = 0;
        for (int j = 0; j < ss.size(); j++) {
            ans = (ans + MUL(base_pow[j], ss[j])) % HashMod;
        }
        mp[ans] = prevss;
        ha.insert(ans);
    }
    vector<bool> dp(n + 1 , false);
    vector<uint64_t> pr(n + 1 , 0);
    dp[0] = true;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            uint64_t cur = get_hash(j - 1 , i - 1);
            if(dp[j - 1] && ha.count(cur)) {
                dp[i] = true;
                pr[i] = j - 1;
                break;
            }
        }
    }
    uint64_t ans = n;
    vector<string> res;
    while(ans > 0) {
        uint64_t x = get_hash(pr[ans] , ans - 1);
        if(mp.count(x))
            res.push_back(mp[x]);
        ans = pr[ans];
    }
    reverse(all(res));
    for (size_t i = 0; i < res.size(); ++i) {
        if (i > 0) cout << ' ';
        cout << res[i];
    }
    cout << endl;
}

int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}

// الحمدلله رب العالمين