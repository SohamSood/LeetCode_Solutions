class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        vector<int> dp(nums.size(),-1);
        dp[0] = 0;
        for(int i = 0;i<nums.size();i++) {
            if(dp[i] == -1) continue;
            for(int j = i+1;j<nums.size();j++) {
                if(abs(nums[i] - nums[j]) <= target) {
                    dp[j] = max(dp[i]+1,dp[j]);
                }
            }
        }
        return dp.back();
    }
};