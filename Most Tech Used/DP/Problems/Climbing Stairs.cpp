// LeetCode : https://leetcode.com/problems/climbing-stairs/description/?envType=problem-list-v2&envId=dynamic-programming
/*
بسم الله الرحمن الرحيم

الْحَمْدُ لِلّهِ الَّذِي هَدَانَا لِهَـذَا وَمَا كُنَّا لِنَهْتَدِيَ لَوْلا أَنْ هَدَانَا اللّهُ

اللهم حرر فلسطين من كيد الصهاينة واجعل كيدهم في نحورهم
اللهم انصر الأقصى والقدس وأهالي غزة وفلسطين اللهم اطمس على أعداء الدين والمدنسين
*/

class Solution {
public:
    int climbStairs(int n) {
        std::vector<int> dp(n + 1, 0);
        dp[n] = 1;
        for(int i = n - 1; i >= 0; i--) {
            if(i + 2 <= n)
                dp[i] += dp[i + 1] + dp[i + 2];
            else
            dp[i] += dp[i + 1];
        }
        return dp[0];
    }
};

// الحمدلله رب العالمين