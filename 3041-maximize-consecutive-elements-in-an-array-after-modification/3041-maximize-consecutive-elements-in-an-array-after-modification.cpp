class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = 1;
        
        pair<int,int> dp ={1,1};
        for(int i = 1;i<nums.size();i++) {
            pair<int,int> dp2  = {1,1};
            if(nums[i] == nums[i-1]){
                dp2 = {dp.first,dp.first+1};
            } else if(nums[i] == nums[i-1]+1) {
                dp2 = {dp.first+1,dp.second+1};
            } else if(nums[i] == nums[i-1] + 2) {
                dp2 = {dp.second+1,1};
            }
            ans = max({ans,dp2.first,dp2.second});
            dp = dp2;
        }
        return ans;
    }
};