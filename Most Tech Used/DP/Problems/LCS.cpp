// atcoder : https://atcoder.jp/contests/dp/tasks/dp_f
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
#define init memset(dp , -1 , sizeof dp) // Note : use it with 0 , -1 only (because it fills each "byte" `not the whole int` with 0x0 ansing a 0 or 0xFF ansing -1) AND it make it in O(N) if you use vector use std::fill instead

void Free_Palestine() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

string s , tt , ss;
int n , m;
int dp[3050][3050];
int check[3050][3050];

int idk(int i , int j) {
    if(i >= n || j >= m)
        return 0;
    int &ret = dp[i][j];
    if(~ret)
        return ret;
    ret = max(idk(i + 1 , j) , idk(i , j + 1));
    if(s[i] == tt[j]) {
        if(ret < idk(i + 1 , j + 1) + 1) {
            ret = idk(i + 1 , j + 1) + 1;
            check[i][j] = 1;
        }
    }
    return ret;
}

void print(int i , int j) {
    if(i >= n || j >= m)
        return;
    if(check[i][j]) {
        cout << s[i];
        print(i + 1 , j + 1);
        return;
    }
    if(idk(i + 1 , j) > idk(i , j + 1))
        print(i + 1 , j);
    else
        print(i , j + 1);
}

void solve() {
    cin >> s >> tt;
    n = s.size() , m = tt.size();
    init;
    memset(check , 0 , sizeof check);
    idk(0 , 0);
    print(0 , 0);
}

int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}
// الحمدلله رب العالمين
