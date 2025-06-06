// Codeforces : https://codeforces.com/contest/977/problem/B
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
#define all(x) rbegin(x), rend(x)
#define NO cout << "NO" << endl
#define YES cout << "YES" << endl
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
const int N = 1e5 + 5;

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
    base_pow[0] = 1;
    for (int i = 1; i < N; i++) {
        base_pow[i] = MUL(base_pow[i - 1], base);
    }
}

struct PolyHash {
    vector<int64_t> pref, suf; // Prefix and suffix hashes
    string s;

    PolyHash(const string &str) : s(str) {
        if (!base_pow[0]) pre(); // Initialize base powers if not already done

        int n = s.size();
        assert(n < N); // Ensure the size is within bounds
        pref.resize(n + 3, 0), suf.resize(n + 3, 0);

        // Compute prefix hashes
        for (int i = 1; i <= n; i++) {
            pref[i] = MUL(pref[i - 1], base) + s[i - 1];
            if (pref[i] >= HashMod) pref[i] -= HashMod;
        }

        // Compute suffix hashes
        for (int i = n; i >= 1; i--) {
            suf[i] = MUL(suf[i + 1], base) + s[i - 1];
            if (suf[i] >= HashMod) suf[i] -= HashMod;
        }
    }

    // Update the hash after a character change
    void update(int pos, char ch) {
        int n = s.size();
        s[pos] = ch;

        // Recompute prefix hashes from pos to end
        for (int i = pos + 1; i <= n; i++) {
            pref[i] = MUL(pref[i - 1], base) + s[i - 1];
            if (pref[i] >= HashMod) pref[i] -= HashMod;
        }

        // Recompute suffix hashes from pos to start
        for (int i = pos + 1; i >= 1; i--) {
            suf[i] = MUL(suf[i + 1], base) + s[i - 1];
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
        int64_t h = suf[l + 1] - MUL(base_pow[r - l + 1], suf[r + 2]);
        return h < 0 ? h + HashMod : h;
    }
};

long long randomLongLong(long long l, long long r) {
    random_device rd;
    mt19937_64 rng(rd());
    uniform_int_distribution<long long> dist(l, r);
    return dist(rng);
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<uint64_t , int> mp;
    map<uint64_t , string> ans;
    for (int i = 0; i < n - 1; ++i) {
        string a = "";
        a += s[i];
        a += s[i + 1];
        PolyHash ph(a);
        mp[ph.get_hash(0 , 1)]++;
        ans[ph.get_hash(0 , 1)] = a;
    }
    string res;
    int mx = 0;
    for(auto it : mp) {
        if(it.second > mx) {
            mx = it.second;
            res = ans[it.first];
        }
    }
    cout << res << endl;
}

int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}

// الحمدلله رب العالمين