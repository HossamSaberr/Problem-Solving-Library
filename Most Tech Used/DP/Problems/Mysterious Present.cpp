// Codeforces : https://codeforces.com/contest/4/problem/D
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
#define init memset(dp , -1 , sizeof dp) // Note : Never use it with N = 2 * 1e5 !!! && use it with 0 , -1 only (because it fills each "byte" `not the whole int` with 0x0 ansing a 0 or 0xFF ansing -1) AND it make it in O(N) if you use vector use std::fill instead

void Free_Palestine() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int n , h , w , dp[5005];
vector<array<int , 3>> arr;

int idk(int i) {
    if(i == n)
        return 0;
    int &ret = dp[i];
    if(~ret)
        return ret;
    ret = 1;
    for (int j = i + 1; j < n; ++j) {
        if (arr[j][0] > arr[i][0] && arr[j][1] > arr[i][1])
            ret = max(ret , idk(j) + 1);
    }
    return ret;
}

void build(int i) {
    cout << arr[i][2] << ' ';
    for (int j = i + 1; j < n; ++j) {
        if (arr[j][0] > arr[i][0] && arr[j][1] > arr[i][1] && dp[i] == dp[j] + 1) {
            build(j);
            break;
        }
    }
}

void solve() {
    cin >> n >> h >> w;
    for (int i = 0; i < n; ++i) {
        int a , b;
        cin >> a >> b;
        arr.push_back({a , b , i + 1});
    }
    sort(all(arr));
    init;
    int ans = 0;
    for(int i = 0; i < n; ++i){
        if(arr[i][0] > h && arr[i][1] > w)
            ans = max(ans , idk(i));
    }
    cout << ans << endl;
    for (int i = 0; i < n; ++i) {
        if(arr[i][0] > h && arr[i][1] > w && ans == dp[i]) {
            build(i);
            break;
        }
    }
}

int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}

// الحمدلله رب العالمين