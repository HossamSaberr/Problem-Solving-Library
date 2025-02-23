// CSES : https://cses.fi/problemset/task/2103/
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
 
class Substring{
public:
    string s;
    int n;
    vector<int> suffix_array;
    Substring(string str){
        s = str;
        s+="$";
        n = s.size();
        suffix_array_construction();
    }
    vector<int> sort_cyclic_shifts() {
        // int n = s.size();
        const int alphabet = 256;
        vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
        for (int i = 0; i < n; i++)
            cnt[s[i]]++;
        for (int i = 1; i < alphabet; i++)
            cnt[i] += cnt[i-1];
        for (int i = 0; i < n; i++)
            p[--cnt[s[i]]] = i;
        c[p[0]] = 0;
        int classes = 1;
        for (int i = 1; i < n; i++) {
            if (s[p[i]] != s[p[i-1]])
                classes++;
            c[p[i]] = classes - 1;
        }
        vector<int> pn(n), cn(n);
        for (int h = 0; (1 << h) < n; ++h) {
            for (int i = 0; i < n; i++) {
                pn[i] = p[i] - (1 << h);
                if (pn[i] < 0)
                    pn[i] += n;
            }
            fill(cnt.begin(), cnt.begin() + classes, 0);
            for (int i = 0; i < n; i++)
                cnt[c[pn[i]]]++;
            for (int i = 1; i < classes; i++)
                cnt[i] += cnt[i-1];
            for (int i = n-1; i >= 0; i--)
                p[--cnt[c[pn[i]]]] = pn[i];
            cn[p[0]] = 0;
            classes = 1;
            for (int i = 1; i < n; i++) {
                pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
                pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
                if (cur != prev)
                    ++classes;
                cn[p[i]] = classes - 1;
            }
            c.swap(cn);
        }
        return p;
    }
    void suffix_array_construction() {
        suffix_array = sort_cyclic_shifts();
    }
    vector<int> get_suffix_array(){
        vector<int> sorted_shifts = suffix_array;
        sorted_shifts.erase(sorted_shifts.begin());
        return sorted_shifts;
    }
    int getSubstringNumber(string t){
        int m = t.size();
        int L = 0,R = n-1;
        bool isPres = true;
        for(int i=0;i<m;i++){
            int l = L,r = R;
            int res = R+1;
            // upper bound
            while(l<=r){
                int mid = (l+r)/2;
                if( suffix_array[mid]+i>=n or s[ suffix_array[mid]+i ]<=t[i] ){
                    l = mid+1;
                }else{
                    res = mid;
                    r = mid-1;
                }
            }
            if(  res == 0 or suffix_array[res-1]+i>=n or s[ suffix_array[res-1]+i ] != t[i] ){
                isPres = false;
                break;
            } else{
                R = res-1;
            }
            // lower bound
            l = L; r = R;
            res = -1;
            while(l<=r){
                int mid = (l+r)/2;
                if( suffix_array[mid]+i>=n or s[ suffix_array[mid]+i ]<t[i] ){
                    l = mid+1;
                }else{
                    res = mid;
                    r = mid-1;
                }
            }
            if( res == -1 or suffix_array[res]+i>=n or s[ suffix_array[res]+i ] != t[i] ){
 
                isPres = false;
                break;
            } else{
                L = res;
            }
        }
        if( isPres ){
 
            return R-L+1;
        } else{
            return 0;
        }
    }
};
 
void solve() {
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<string> h(n);
    Substring k = Substring(s);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
        string p = h[i];
        int f = k.getSubstringNumber(p);
        cout << f << endl;
    }
}
 
int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}

// الحمدلله رب العالمين