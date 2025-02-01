// LeetCode : https://leetcode.com/problems/longest-common-subsequence/description/
/*
بسم الله الرحمن الرحيم

الْحَمْدُ لِلّهِ الَّذِي هَدَانَا لِهَـذَا وَمَا كُنَّا لِنَهْتَدِيَ لَوْلا أَنْ هَدَانَا اللّهُ

اللهم حرر فلسطين من كيد الصهاينة واجعل كيدهم في نحورهم
اللهم انصر الأقصى والقدس وأهالي غزة وفلسطين اللهم اطمس على أعداء الدين والمدنسين
*/

class Solution {
public:
    int dp[1005][1005];  
    string s, ss;      
    
    int idk(int i, int j) {
        if (i == s.size() || j == ss.size())
            return 0;
        int &ret = dp[i][j];
        if (ret != -1)
            return ret;
        if (s[i] == ss[j])
            return ret = 1 + idk(i + 1, j + 1);
        return ret = max(idk(i + 1, j), idk(i, j + 1));
    }

    int longestCommonSubsequence(string text1, string text2) {
        s = text1;
        ss = text2;
        memset(dp, -1, sizeof(dp));
        return idk(0, 0);
    }
};


// الحمدلله رب العالمين