/*Edit Dist Problem */
// o(N * M)
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