// LeetCode : https://leetcode.com/problems/longest-increasing-subsequence/description/?envType=problem-list-v2&envId=dynamic-programming
/*
بسم الله الرحمن الرحيم

الْحَمْدُ لِلّهِ الَّذِي هَدَانَا لِهَـذَا وَمَا كُنَّا لِنَهْتَدِيَ لَوْلا أَنْ هَدَانَا اللّهُ

اللهم حرر فلسطين من كيد الصهاينة واجعل كيدهم في نحورهم
اللهم انصر الأقصى والقدس وأهالي غزة وفلسطين اللهم اطمس على أعداء الدين والمدنسين
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n , 1);
    int ans = 1;
    for (int i = 0; i < arr.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            dp[i] = max(dp[i] , (arr[j] < arr[i] ? dp[j] + 1 : 0));
        }
    }
    for(int i = 1; i < n; i++) {
        ans = max(ans , dp[i]);
    }
    return ans;
    }
};

// الحمدلله رب العالمين