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

    template<typename T>
    PolyHash(const vector<T> &s) {
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

int binpow(int x){
    int ans = 1 , y = base;
    while(x > 0){
        if(x & 1)
            ans = MUL(ans , y);
        y = MUL(y , y);
        x >>= 1;
    }
    return ans;
}

struct KMP {
    //keywords: substring , prefix , suffix , equality
    //typically processing for the pattern similar to the input
    //try: s , s + s , rev(s) , s + 'a' + s ,....

    vector<int> failure;

    void build(const string &s) {
        // failure[i] = length of the longest proper prefix of s[0..i] that is
        // also a suffix of this substring
        int n = (int) s.size();
        if (failure.size() <= s.size())failure.clear(), failure.resize(n);
        for (int i = 1; i < n; i++) {
            int j = failure[i - 1];
            while (j > 0 && s[i] != s[j])
                j = failure[j - 1];
            if (s[i] == s[j])
                j++;
            failure[i] = j;
        }
    }

    static vector<int> pattern(const string &s, const string &t) {
        KMP temp;
        temp.build(t);
        int n = (int) s.size(), m = (int) t.size(), k = 0;
        vector<int> pos;
        for (int i = 0; i < n; i++) {
            while (k > 0 && s[i] != t[k]) {
                k = temp.failure[k - 1];
            }
            if (s[i] == t[k])k++;
            if (k == m) {
                pos.emplace_back(i - m + 1);
                k = temp.failure[k - 1];
            }
        }
        return pos;
    }

    static pair<int , string> LongestPalndromeSuffix(const string &s) {
        KMP temp;
        string rev = s;
        reverse(rev.begin(), rev.end());
        string x = rev + '@' + s;
        temp.build(x);
        int res = temp.failure[x.size() - 1];
        string t = s.substr(0 , s.size() - res);
        reverse(t.begin() , t.end());
        string res2 = s + t;
        return make_pair(res , res2);
    }

    static pair<int,string> LongestPalndromePrefix(const string &s) {
        KMP temp;
        string rev = s;
        reverse(rev.begin(), rev.end());
        string x = s + '@' + rev;
        temp.build(x);
        int res = temp.failure[x.size() - 1];
        string t = s.substr(res) ;
        reverse(t.begin() , t.end());
        string res1 = t + s;
        return make_pair(res , res1);
    }

    static int MinUnit(const string &s) {
        // what is the smallest prefix can build up the string
        KMP temp;
        temp.build(s);
        if (s.size() % (s.size() - temp.failure[s.size() - 1]) != 0)return (int) s.size();
        return (int) s.size() - temp.failure[s.size() - 1];
    }

    static int MinUnitVersion2(const string &s) {
        KMP temp;
        string p = s + s;
        vector<int> res = temp.pattern(p, s);
        if (res.size() >= 2)return res[1];
        else return (int) s.size();
    }

    static vector<int> FreqAllPrefixes(const string &s) {
        // count for every prefix it's frequency as sub string and count it self
        KMP temp;
        temp.build(s);
        vector<int> freq(s.size() + 1);
        for (int i = 0; i < s.size(); i++) {
            ++freq[temp.failure[i]];
        }
        for (int i = (int) s.size() - 1; i > 0; i--) {
            freq[temp.failure[i - 1]] += freq[i];
        }
        freq.erase(freq.begin());
        for (auto &val: freq)val++;
        return freq;
    }
    static int CountUniquePrefixes(const string &s){
        vector<int> temp = KMP::FreqAllPrefixes(s);
        return count(temp.begin() , temp.end() , 1);
    }
    static int UniqueSubStrings(const string &s){
        string cur;
        int n = (int)s.size();
        int res = 0;
        for(int i = 0;i<n;i++){
            cur += s[i];
            string tt = cur;
            reverse(tt.begin() , tt.end());
            res += CountUniquePrefixes(tt);
        }
        return res;
    }
};

struct KMPs
{

    vector<int> s;
    vector<int> lps;

    KMPs(vector<int> &s) : s(s) // s is the pattern
    {
        lps.resize(s.size());
        int j = 0;
        for (int i = 1; i < s.size(); i++)
        {
            while (j > 0 && s[i] != s[j])
                j = lps[j - 1];
            if (s[i] == s[j])
                j++;
            lps[i] = j;
        }
    }

    vector<int> match(vector<int> &t) // t is the text
    {
        vector<int> res;
        int j = 0;
        for (int i = 0; i < t.size(); i++)
        {
            while (j > 0 && t[i] != s[j])
                j = lps[j - 1];
            if (t[i] == s[j])
                j++;
            if (j == s.size())
                res.push_back(i - j + 1), j = lps[j - 1];
        }
        return res;
    }
};