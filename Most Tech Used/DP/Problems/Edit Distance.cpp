// CSES : https://cses.fi/problemset/task/1639/
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
#define NO cout << "NO" << endl
#define YES cout << "YES" << endl
#define init memset(dp , -1 , sizeof dp)
 
void Free_Palestine() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
 
string s , s2;
int dp[5005][5005];
 
int idk(int i , int j) {
    if (i < 0)
        return j + 1;;
    if (j < 0)
        return i + 1;
    int &ret = dp[i][j];
    if(~ret)
        return ret;
    if(s[i] == s2[j])
        ret = idk(i - 1 , j - 1);
    else
        ret = 1 + min({idk(i - 1 , j) , idk(i , j - 1) , idk(i - 1 , j - 1)});
    return ret;
}
 
void solve() {
    cin >> s >> s2;
    memset(dp , -1 , sizeof dp);
    cout << idk(s.size() - 1 , s2.size() - 1) << endl;
}
 
int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}
// الحمدلله رب العالمين