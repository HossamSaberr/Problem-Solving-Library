// Codeforces : https://codeforces.com/problemset/problem/500/B
/*
بسم الله الرحمن الرحيم

الْحَمْدُ لِلّهِ الَّذِي هَدَانَا لِهَـذَا وَمَا كُنَّا لِنَهْتَدِيَ لَوْلا أَنْ هَدَانَا اللّهُ

اللهم حرر فلسطين من كيد الصهاينة واجعل كيدهم في نحورهم
اللهم انصر الأقصى والقدس وأهالي غزة وفلسطين اللهم اطمس على أعداء الدين والمدنسين
*/

#include <bits/stdc++.h>

using namespace std;

const long double pii = 3.1415926536;
//#define int long long
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

void dfs(int n, vector<int>&v1,  vector<int>&idx, vector<int>&vis,vector<vector<int>>vec,vector<int>&v){
    v1.push_back(v[n]);
    idx.push_back(n);
    vis[n]=1;
    for(auto &c:vec[n]){
        if(!vis[c]){
            dfs(c,v1,idx,vis,vec,v);
        }
    }
}
void solve(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(auto&c:v)
        cin>>c;
    vector<string>s(n);
    for(auto&c:s)
        cin>>c;
    vector<vector<int>>vec(n);
    for(int i=0;i<n;i++){
        for(int j = 0;j <n;j++) {
            if(s[i][j]=='1') {
                vec[i].push_back(j);
                vec[j].push_back(i);
            }
        }
    }
    vector<int> vis(n+1);
    for(int i =0;i<n;i++){
        if(!vis[i]){
            vector<int>v1,idx;
            dfs(i,v1,idx,vis,vec,v);
            sort(all(v1));
            sort(all(idx));
            for(int k =0;k<idx.size();k++){
                v[idx[k]]=v1[k];
            }
        }
    }
    for(auto&c:v){
        cout<<c<<" ";
    }
}

int32_t main() {
    Free_Palestine();
    Shity Code By Hossam
    return 0;
}

// الحمدلله رب العالمين