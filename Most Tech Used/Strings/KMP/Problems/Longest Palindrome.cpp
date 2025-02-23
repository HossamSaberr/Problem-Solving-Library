// CSES : https://cses.fi/problemset/task/1111/
/*
بسم الله الرحمن الرحيم
 
الْحَمْدُ لِلّهِ الَّذِي هَدَانَا لِهَـذَا وَمَا كُنَّا لِنَهْتَدِيَ لَوْلا أَنْ هَدَانَا اللّهُ
 
اللهم حرر فلسطين من كيد الصهاينة واجعل كيدهم في نحورهم
اللهم انصر الأقصى والقدس وأهالي غزة وفلسطين اللهم اطمس على أعداء الدين والمدنسين
*/
 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
struct KMP {
    vector<int> failure, z;
 
    void build(const string &s) {
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
};
 
int main() {
    string s;
    cin >> s;
    KMP kmp;
    cout << kmp.longestPalindromicSubstring(s) << "\n";
    return 0;
}
 
// الحمدلله رب العالمين