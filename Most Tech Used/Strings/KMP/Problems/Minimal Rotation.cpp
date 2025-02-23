// CSES : https://cses.fi/problemset/task/1110/
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
 
 
struct KMP {
    //keywords: substring , prefix , suffix , equality
    //typically processing for the pattern similar to the input
    //try: s , s + s , rev(s) , s + 'a' + s ,....
 
    vector<int> failure, z;
 
    void computePrefixFunction(const string &s) { // prefix function its the failure function
        int n = (int) s.size();
        if (failure.size() <= s.size()) failure.clear(), failure.resize(n);
        for (int i = 1; i < n; i++) {
            int j = failure[i - 1];
            while (j > 0 && s[i] != s[j])
                j = failure[j - 1];
            if (s[i] == s[j])
                j++;
            failure[i] = j;
        }
    }
 
    void computeZFunction(const string &s) {
        int n = s.size(), l = 0, r = 0;
        z.assign(n, 0);
        for (int i = 1; i < n; i++) {
            if (i <= r) z[i] = min(r - i + 1, z[i - l]);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
            if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
        }
    }
 
    static vector<int> pattern(const string &s, const string &t) {
        KMP temp;
        temp.computePrefixFunction(t);
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
 
    static pair<int , string> LongestPalndromeSuffix(const string &s) {// min char to add in the end
        KMP temp;
        string rev = s;
        reverse(rev.begin(), rev.end());
        string x = rev + '@' + s;
        temp.computePrefixFunction(x);
        int res = temp.failure[x.size() - 1];
        string t = s.substr(0 , s.size() - res);
        reverse(t.begin() , t.end());
        string res2 = s + t;
        return make_pair(res , res2);
    }
 
    static pair<int,string> LongestPalndromePrefix(const string &s) { // min char to add in the begin
        KMP temp;
        string rev = s;
        reverse(rev.begin(), rev.end());
        string x = s + '@' + rev;
        temp.computePrefixFunction(x);
        int res = temp.failure[x.size() - 1];
        string t = s.substr(res) ;
        reverse(t.begin() , t.end());
        string res1 = t + s;
        return make_pair(res , res1);
    }
 
    static int MinUnit(const string &s) {
        // what is the smallest prefix can build up the string
        KMP temp;
        temp.computePrefixFunction(s);
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
        temp.computePrefixFunction(s);
        vector<int> freq(s.size() + 1);
        for (int i = 0; i < s.size(); i++) {
            ++freq[temp.failure[i]];
        }
        for (int i = (int) s.size() - 1; i > 0; i--) {
            freq[temp.failure[i - 1]] += freq[i];
        }
        freq.erase(freq.begin()); // remove this line if you case about the whole string not prober prefix
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
    bool hasRepeatKMP(const string &s, const string &pat) {
        int n = s.size(), m = pat.size(), j = 0;
        computePrefixFunction(pat);
        int count = 0;
 
        for (int i = 0; i < n; i++) {
            while (j > 0 && s[i] != pat[j]) j = failure[j - 1];
            if (s[i] == pat[j]) j++;
            if (j == m) {
                count++;
                j = failure[j - 1];
                if (count >= 2) return true;
            }
        }
        return false;
    }
 
    string longestRepeatingSubstring(const string &s) {
        int n = s.size();
        int low = 1, high = n - 1, bestLen = 0;
        string bestSub = "-1";
 
        while (low <= high) {
            int mid = (low + high) / 2;
            bool found = false;
            string candidate;
 
            for (int i = 0; i + mid <= n; i++) {
                string sub = s.substr(i, mid);
                if (hasRepeatKMP(s, sub)) {
                    found = true;
                    candidate = sub;
                    break;
                }
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
 
    string longestPalindromicSubstring(const string &s) {
        int n = s.size();
        if (n == 0) return "";
        if (n == 1) return s; // Handle single character case
 
        string t = "#";
        for (char c : s) t += c, t += "#";
        int m = t.size();
        vector<int> p(m, 0);
        int c = 0, r = 0;
 
        for (int i = 1; i < m; i++) {
            int mirr = 2 * c - i;
            if (i < r) p[i] = min(r - i, p[mirr]);
            while (i + p[i] + 1 < m && i - p[i] - 1 >= 0 && t[i + p[i] + 1] == t[i - p[i] - 1])
                p[i]++;
            if (i + p[i] > r) {
                c = i;
                r = i + p[i];
            }
        }
 
        int maxLen = 0, center = 0;
        for (int i = 0; i < m; i++) {
            if (p[i] > maxLen) {
                maxLen = p[i];
                center = i;
            }
        }
        int start = (center - maxLen) / 2;
        return s.substr(start, maxLen);
    }
    string minimalRotation(const string &s) { // min rotation to get a smallest lexographicly string rotian is shift the string For example, the rotations of acab are acab, caba, abac, and baca.
            int n = s.size();
            string doubled = s + s;
            vector<int> f(2 * n, -1);
            int k = 0;
            for (int j = 1; j < 2 * n; j++) {
                char c = doubled[j];
                int i = f[j - k - 1];
                while (i != -1 && c != doubled[k + i + 1]) {
                    if (c < doubled[k + i + 1]) k = j - i - 1;
                    i = f[i];
                }
                if (c != doubled[k + i + 1]) {
                    if (c < doubled[k]) k = j;
                    f[j - k] = -1;
                } else {
                    f[j - k] = i + 1;
                }
            }
            return doubled.substr(k, n);
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
 
void solve() {
    string s;
    cin >> s;
    KMP k;
    auto ans = k.minimalRotation(s);
    cout << ans << endl;
}
 
int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}
 
// الحمدلله رب العالمين
