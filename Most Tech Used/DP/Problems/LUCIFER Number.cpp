// spoj : https://www.spoj.com/problems/LUCIFER/
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
#define By int t = 1;cin >> t;
#define Hossam while(t--) { sieve(); solve(); }
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

int l , r;
string s;
int dp[20][2][100][100];
bool isPrime[100];

void sieve() {
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i < 100; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j < 100; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

int idk(int i , bool mx , int sumodd , int sumeven) {
    if(i == s.size()) {
        int x = sumeven - sumodd;
        if(x <= 1)
            return 0;
        return (isPrime[x]);
    }
    int &ret = dp[i][mx][sumodd][sumeven];
    if(~ret)
        return ret;
    ret = 0;
    int end = mx ? s[i] - '0' : 9;
    for (int j = 0; j <= end; ++j) {
        if((s.size() - i) % 2 ==  1)
            ret += idk(i + 1 , mx && (j == end) , sumodd + j , sumeven);
        else
            ret += idk(i + 1 , mx && (j == end) , sumodd , sumeven + j);
    }
    return ret;
}

void solve() {
    cin >> l >> r;
    s = to_string(r);
    init;
    int ans = idk(0 , 1 , 0 , 0);
    s = to_string(l - 1);
    init;
    ans -= idk(0 , 1 , 0 , 0);
    cout << ans << endl;
}

int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}
// الحمدلله رب العالمين