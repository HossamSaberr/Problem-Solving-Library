// Atcoder : https://atcoder.jp/contests/abc049/tasks/arc065_b?lang=en
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
#define ll long long
#define endl '\n'
#define Shity ios_base::sync_with_stdio(false);
#define Code cin.tie(nullptr);cout.tie(nullptr);
#define By int t = 1;//cin >> t;
#define Hossam while(t--) { solve(); }
#define all(x) begin(x) , end(x)
#define NO cout << "No" << endl
#define YES cout << "Yes" << endl
#define init memset(dp , -1 , sizeof dp) // Note : Never use it with N = 2 * 1e5 !!! && use it with 0 , -1 only (because it fills each "byte" `not the whole int` with 0x0 ansing a 0 or 0xFF ansing -1) AND it make it in O(N) if you use vector use std::fill instead

void Free_Palestine() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

const ll INF = 2e18;
const ll MOD = 1e9+7;

void dfs(ll u, vector<ll> &comp, vector<vector<ll>> &A, ll c){
    comp[u]=c;
    for (auto v:A[u]){
        if (comp[v]==-1) dfs(v, comp, A, c);
    }
}

void solve(){
    ll n , k , l;
    cin >> n >> k >> l;
    vector<vector<ll>> ro(n + 1) , ra(n + 1);
    for (ll i = 0; i < k; i++){
        ll u , v;
        cin >> u >> v;
        ro[u].push_back(v);
        ro[v].push_back(u);
    }
    for (ll i = 0; i < l; i++){
        ll u , v;
        cin >> u >> v;
        ra[u].push_back(v);
        ra[v].push_back(u);
    }
    vector<ll> roc(n + 1 , -1) , rac(n + 1 , -1);
    ll cro = 0 , cra = 0;
    for (ll i = 1; i <= n; i++){
        if (roc[i] == -1) {
            dfs(i, roc, ro, cro);
            cro++;
        }
        if (rac[i] == -1) {
            dfs(i, rac, ra, cra);
            cra++;
        }
    }
    map<pair<ll , ll> , ll> cnt;
    for (ll i = 1; i <= n; i++){
        cnt[{roc[i], rac[i]}]++;
    }
    for (ll i = 1; i <= n; i++){
        cout << cnt[{roc[i], rac[i]}] << " ";
    }
}

int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}

// الحمدلله رب العالمين