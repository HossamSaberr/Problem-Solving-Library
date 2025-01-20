// LeetCode : https://leetcode.com/problems/n-th-tribonacci-number/description/?envType=problem-list-v2&envId=dynamic-programming
/*
بسم الله الرحمن الرحيم

الْحَمْدُ لِلّهِ الَّذِي هَدَانَا لِهَـذَا وَمَا كُنَّا لِنَهْتَدِيَ لَوْلا أَنْ هَدَانَا اللّهُ

اللهم حرر فلسطين من كيد الصهاينة واجعل كيدهم في نحورهم
اللهم انصر الأقصى والقدس وأهالي غزة وفلسطين اللهم اطمس على أعداء الدين والمدنسين
*/

class Solution {
public:
    int tribonacci(int n) {
        vector<int> dp(n + 3 , 0);
        dp[1] = 1;
        dp[2] = 1;
        for(int i = 3; i <= n; i++)
            dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
        return dp[n];
    }
};

// الحمدلله رب العالمين