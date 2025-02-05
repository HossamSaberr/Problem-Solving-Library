// Codeforces : https://codeforces.com/contest/292/problem/B
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

int n , m;
const int N = 1e5 + 5;
vector<vector<int>> adj(N);
vector<int> deg(N);

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int from , to;
        cin >> from >> to;
        from--;
        to--;
        deg[from]++;
        deg[to]++;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    set<int> st;
    for (int i = 0; i < n; ++i) {
        st.insert(deg[i]);
    }
    int one = 0 , two = 0 , another = 0;
    for(int i = 0; i < n; ++i) {
        int it = deg[i];
        if(it == 1)
            one++;
        else if(it == 2)
            two++;
        else
            another++;
    }
    if(two == n && one == 0 && another == 0)
        cout << "ring topology" << endl;
    else if(one == n - 1 && another == 1 && two == 0)
        cout << "star topology" << endl;
    else if(one == 2 && two == n - 2 && another == 0)
        cout << "bus topology" << endl;
    else
        cout << "unknown topology" << endl;
}

int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}

// الحمدلله رب العالمين