int longestPalindromeInRange(string &s, int l, int r) {
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    int maxLength = 1; 
    for (int i = l; i <= r; i++) {
        dp[i][i] = true;
        if (i<r && s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            maxLength = 2;
        }
    }
    for (int len = 3; len <= (r - l + 1); len++) {
        for (int i = l; i <= r - len + 1; i++) {
            int j = i + len - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
                maxLength = len;
            }
        }
    }
 
    return maxLength;
}