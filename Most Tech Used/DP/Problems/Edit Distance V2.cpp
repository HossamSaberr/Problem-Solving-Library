// LeetCode : https://leetcode.com/problems/edit-distance/description/?envType=problem-list-v2&envId=dynamic-programming
/*
بسم الله الرحمن الرحيم

الْحَمْدُ لِلّهِ الَّذِي هَدَانَا لِهَـذَا وَمَا كُنَّا لِنَهْتَدِيَ لَوْلا أَنْ هَدَانَا اللّهُ

اللهم حرر فلسطين من كيد الصهاينة واجعل كيدهم في نحورهم
اللهم انصر الأقصى والقدس وأهالي غزة وفلسطين اللهم اطمس على أعداء الدين والمدنسين
*/

class Solution {
public:
    int idk(int i , int j , string word1 , string word2 , int dp[]) {
        if (i < 0)
            return j + 1;
        if (j < 0)
            return i + 1;
        int &ret = dp[i * word2.size() + j]; 
        if (~ret)
            return ret;
        if(word1[i] == word2[j])
            ret = idk(i - 1 , j - 1, word1, word2, dp);
        else
            ret = 1 + min({idk(i - 1 , j, word1, word2, dp) , idk(i , j - 1, word1, word2, dp), idk(i - 1 , j - 1, word1, word2, dp)});
        return ret;
    }

    int minDistance(string word1, string word2) {
        int dp[(word1.size() + 1) * (word2.size() + 1)];
        memset(dp , -1 , sizeof dp);
        return idk(word1.size() - 1 , word2.size() - 1 , word1 , word2 , dp);
    }
};

// الحمدلله رب العالمين