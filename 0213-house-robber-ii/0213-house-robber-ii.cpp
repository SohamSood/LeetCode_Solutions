class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<pair<int,int>> dp(nums.size(),{0,0});
        int maxans = nums[0];
        dp[0] = {nums[0],0};
        for(int i = 1;i<nums.size();i++) {
            int case1 = 0; //with 
            int case2 = 0; //without
            for(int j = 0;j<i-1;j++) {
                case1 = max(dp[j].first,case1);
                case2 = max(dp[j].second,case2);
            }
            dp[i] = {case1+nums[i],case2+nums[i]};
            if(i == dp.size()-1) maxans = max(maxans,dp[i].second);
            else {
                maxans = max(maxans,dp[i].first);
                maxans = max(maxans,dp[i].second);
            } 
        }
        // for(int i = 0;i<dp.size();i++) {
        //     cout<<nums[i]<<" with -> " <<dp[i].first<< "without->  "<<dp[i].second<<endl;
        // }
        return maxans;
    }
};