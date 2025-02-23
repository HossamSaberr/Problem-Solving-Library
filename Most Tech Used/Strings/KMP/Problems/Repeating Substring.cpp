// CSES : https://cses.fi/problemset/task/2106/
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
 
void Free_Palestine() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
 
#include <bits/stdc++.h>
using namespace std;
 
struct KMP {
    static const int MOD1 = 1e9 + 7, BASE1 = 31;
    static const int MOD2 = 1e9 + 9, BASE2 = 37;
 
    struct PairHash {
        size_t operator()(const pair<long long, long long>& p) const {
            return hash<long long>()(p.first) ^ (hash<long long>()(p.second) << 1);
        }
    };
 
    pair<vector<long long>, vector<long long>> computeHashes(const string &s, int len) {
        int n = s.size();
        vector<long long> hash1(n - len + 1, 0), hash2(n - len + 1, 0);
        long long h1 = 0, h2 = 0, p1 = 1, p2 = 1;
 
        for (int i = 0; i < len; i++) {
            h1 = (h1 * BASE1 + (s[i] - 'a' + 1)) % MOD1;
            h2 = (h2 * BASE2 + (s[i] - 'a' + 1)) % MOD2;
            if (i < len - 1) {
                p1 = (p1 * BASE1) % MOD1;
                p2 = (p2 * BASE2) % MOD2;
            }
        }
        hash1[0] = h1, hash2[0] = h2;
 
        for (int i = 1; i + len <= n; i++) {
            h1 = (h1 - (s[i - 1] - 'a' + 1) * p1 % MOD1 + MOD1) % MOD1;
            h1 = (h1 * BASE1 + (s[i + len - 1] - 'a' + 1)) % MOD1;
            hash1[i] = h1;
 
            h2 = (h2 - (s[i - 1] - 'a' + 1) * p2 % MOD2 + MOD2) % MOD2;
            h2 = (h2 * BASE2 + (s[i + len - 1] - 'a' + 1)) % MOD2;
            hash2[i] = h2;
        }
 
        return {hash1, hash2};
    }
 
    string longestRepeatingSubstring(const string &s) {
        int n = s.size();
        int low = 1, high = n - 1, bestLen = 0;
        string bestSub = "-1";
 
        while (low <= high) {
            int mid = (low + high) / 2;
            unordered_set<pair<long long, long long>, PairHash> seen;
            bool found = false;
            string candidate;
 
            auto [hash1, hash2] = computeHashes(s, mid);
 
            for (int i = 0; i < hash1.size(); i++) {
                pair<long long, long long> h = {hash1[i], hash2[i]};
                if (seen.count(h)) {
                    found = true;
                    candidate = s.substr(i, mid);
                    break;
                }
                seen.insert(h);
            }
 
            if (found) {
                bestLen = mid;
                bestSub = candidate;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
 
        return bestSub;
    }
};
 
void solve() {
    string s;
    cin >> s;
    KMP kmp;
    cout << kmp.longestRepeatingSubstring(s) << endl;
}
 
int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}
 
// الحمدلله رب العالمين