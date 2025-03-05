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

const int N = 2e5 + 5 , MOD = 1e9 + 7;
const int dx[] = {0, 0, 1, -1, -1, 1, -1, 1};
const int dy[] = {1, -1, 0, 0, 1, 1, -1, -1};
const char dir[] = {'R', 'L', 'D', 'U'};
int add(int x, int a) { return ((a % MOD) + (x % MOD)) % MOD; }
int mul(int a, int b) { return ((a % MOD) * (b % MOD)) % MOD; }
int sub(int a, int b) { return ((a % MOD) - (b % MOD) + MOD) % MOD; }
int binpow(int x,int y,int m = MOD){x%=m;int ans=1;while(y>0){if(y&1)ans=((ans%m)*(x%m))%m;x=((x%m)*(x%m))%m;y/=2;}return ans;}
int gcd(int a , int b) {if(b == 0) return a; return gcd(b , a % b);}

void Free_Palestine() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

string s1 , s2;
int dp[1005][1005];

int rec(int i , int j) {
    //base case
    if(i == s1.size() && j == s2.size())
        return 0;
    if(i == s1.size())
        return s2.size() - j;
    if(j == s2.size())
        return s1.size() - i;
    int &ret = dp[i][j];
    if(~ret)
        return ret;
    if(s1[i] == s2[j])
        return ret = rec(i + 1 , j + 1);
    else {
        int ch1 = rec(i + 1 , j) + 1; // delete
        int ch2 = rec(i , j + 1) + 1; // inseart
        int ch3 = rec(i + 1 , j + 1) + 1;// replace
        return dp[i][j] = min({ch1 , ch2 , ch3}); // dp[i][j] = dp[i + 1][j] + 1
    }
}
void build(int i , int j) {
    //base case
    if(i == s1.size() && j == s2.size()) {
        return;
    }
    if(i == s1.size()){
        for(; j < s2.size(); j++) {
            cout << "INSERT " << j + 1 << ' ' << s2[j] << endl;
        }
        return;
    }
    if(j == s2.size()){
        for(; i < s1.size(); i++) {
            cout << "DELETE " << j + 1 << endl;
        }
        return;
    }
    if(s1[i] == s2[j]) {
        build(i + 1 , j + 1);
        return;
    }
    if(dp[i][j] == dp[i + 1][j] + 1) {// delete
        cout << "DELETE " << j + 1 << endl;
        build(i + 1 , j);
        return;
    }
    else if(dp[i][j] == dp[i][j + 1] + 1) { // inseart
        cout << "INSERT " << j + 1 << " " << s2[j] << endl;
        build(i , j + 1);
        return;
    }
    else { //replace
        cout << "REPLACE " << j + 1 << ' ' << s2[j] << endl;
        build(i + 1 , j + 1);
        return;
    }
    return;
}

void solve() {
    cin >> s1 >> s2;
    init;
    cout << rec(0 , 0) << endl;
    build(0 , 0);
}

int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}

// الحمدلله رب العالمين