// LeetCode : https://leetcode.com/problems/number-of-subarrays-that-match-a-pattern-i/description/?envType=problem-list-v2&envId=rolling-hash
/*
بسم الله الرحمن الرحيم

الْحَمْدُ لِلّهِ الَّذِي هَدَانَا لِهَـذَا وَمَا كُنَّا لِنَهْتَدِيَ لَوْلا أَنْ هَدَانَا اللّهُ

اللهم حرر فلسطين من كيد الصهاينة واجعل كيدهم في نحورهم
اللهم انصر الأقصى والقدس وأهالي غزة وفلسطين اللهم اطمس على أعداء الدين والمدنسين
*/

class Solution {
public:

    int idk(int i , int k , vector<int>& nums, vector<int>& pattern, vector<vector<int>>& dp) {
        if(k == pattern.size())
        return 1;
        if(i == nums.size())
            return 0;
        int &ret = dp[i][k];
        if(~ret)
            return ret;
        if(pattern[k] == 1) {
            if(i + 1 < nums.size()) {
                if(nums[i + 1] > nums[i])
                    return ret = idk(i + 1 , k + 1 , nums , pattern , dp);
            }
        }
        else  if(pattern[k] == 0) {
            if(i + 1 < nums.size()) {
                if(nums[i + 1] == nums[i])
                    return ret = idk(i + 1 , k + 1 , nums , pattern , dp);
            }
        }
        else  if(pattern[k] == -1) {
            if(i + 1 < nums.size()) {
                if(nums[i + 1] < nums[i])
                    return ret = idk(i + 1 , k + 1 , nums , pattern , dp);
            }
        }
        return ret = 0;
    }
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int ans = 0;
        vector<vector<int>>dp(nums.size(), vector<int>(pattern.size(), -1));
        for(int i = 0; i < nums.size(); ++i)
            ans += idk(i , 0 , nums , pattern , dp);
        return ans;
    }
};

// الحمدلله رب العالمين