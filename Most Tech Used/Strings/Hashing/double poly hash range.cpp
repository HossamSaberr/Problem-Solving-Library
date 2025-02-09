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

const uint64_t HashMod = (1ULL << 61) - 1; // 2^61 - 1
const uint64_t seed = chrono::system_clock::now().time_since_epoch().count();
const uint64_t base1 = mt19937_64(seed)() % (HashMod / 3) + (HashMod / 3);
const uint64_t base2 = mt19937_64(seed + 1)() % (HashMod / 3) + (HashMod / 3);
const uint64_t N = 1e6 + 5;

uint64_t base1_pow[N], base2_pow[N];

// Safe modular multiplication function
int64_t MUL(uint64_t a, uint64_t b) {
    uint64_t l1 = (uint32_t) a, h1 = a >> 32, l2 = (uint32_t) b, h2 = b >> 32;
    uint64_t l = l1 * l2, m = l1 * h2 + l2 * h1, h = h1 * h2;
    uint64_t ret = (l & HashMod) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
    ret = (ret & HashMod) + (ret >> 61);
    ret = (ret & HashMod) + (ret >> 61);
    return (int64_t) ret - 1;
}

// Precompute powers of base1 and base2
void pre() {
    base1_pow[0] = 1;
    base2_pow[0] = 1;
    for (int i = 1; i < N; i++) {
        base1_pow[i] = MUL(base1_pow[i - 1], base1);
        base2_pow[i] = MUL(base2_pow[i - 1], base2);
    }
}

struct PolyHash {
    vector<int64_t> pref1, pref2; // Prefix hashes for base1 and base2
    vector<int64_t> suf1, suf2;   // Suffix hashes for base1 and base2

    template<typename T>
    PolyHash(const vector<T> &ar) {
        if (!base1_pow[0]) pre(); // Initialize base powers if not already done

        int n = ar.size();
        assert(n < N); // Ensure the size is within bounds
        pref1.resize(n + 3, 0), pref2.resize(n + 3, 0);
        suf1.resize(n + 3, 0), suf2.resize(n + 3, 0);

        // Compute prefix hashes
        for (int i = 1; i <= n; i++) {
            pref1[i] = MUL(pref1[i - 1], base1) + ar[i - 1] + 997;
            if (pref1[i] >= HashMod) pref1[i] -= HashMod;
            pref2[i] = MUL(pref2[i - 1], base2) + ar[i - 1] + 997;
            if (pref2[i] >= HashMod) pref2[i] -= HashMod;
        }

        // Compute suffix hashes
        for (int i = n; i >= 1; i--) {
            suf1[i] = MUL(suf1[i + 1], base1) + ar[i - 1] + 997;
            if (suf1[i] >= HashMod) suf1[i] -= HashMod;
            suf2[i] = MUL(suf2[i + 1], base2) + ar[i - 1] + 997;
            if (suf2[i] >= HashMod) suf2[i] -= HashMod;
        }
    }

    // Constructor for strings
    explicit PolyHash(const string &str) : PolyHash(vector<char>(str.begin(), str.end())) {}

    // Get hash for substring [l, r] using base1
    uint64_t get_hash1(int l, int r) {
        int64_t h = pref1[r + 1] - MUL(base1_pow[r - l + 1], pref1[l]);
        return h < 0 ? h + HashMod : h;
    }

    // Get hash for substring [l, r] using base2
    uint64_t get_hash2(int l, int r) {
        int64_t h = pref2[r + 1] - MUL(base2_pow[r - l + 1], pref2[l]);
        return h < 0 ? h + HashMod : h;
    }

    // Get reverse hash for substring [l, r] using base1
    uint64_t rev_hash1(int l, int r) {
        int64_t h = suf1[l + 1] - MUL(base1_pow[r - l + 1], suf1[r + 2]);
        return h < 0 ? h + HashMod : h;
    }

    // Get reverse hash for substring [l, r] using base2
    uint64_t rev_hash2(int l, int r) {
        int64_t h = suf2[l + 1] - MUL(base2_pow[r - l + 1], suf2[r + 2]);
        return h < 0 ? h + HashMod : h;
    }
};

bool are_substrings_equal(PolyHash &hasher1, PolyHash &hasher2, int l1, int r1, int l2, int r2) {
    return hasher1.get_hash1(l1, r1) == hasher2.get_hash1(l2, r2) &&
           hasher1.get_hash2(l1, r1) == hasher2.get_hash2(l2, r2);
}

void solve() {
    string s1 = "Hossam";
    string s2 = "Hossam";
    PolyHash hasher1(s1), hasher2(s2);

    int l1 = 0, r1 = 3; // Substring "Hoss" in s1
    int l2 = 0, r2 = 3; // Substring "Hoss" in s2

    if (are_substrings_equal(hasher1, hasher2, l1, r1, l2, r2)) {
        cout << "Substrings are equal!\n";
    } else {
        cout << "Substrings are not equal!\n";
    }
}

int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}

// الحمدلله رب العالمين