class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minval = nums[0];
        for(int i = 1;i<nums.size();i++) {
            minval = min(minval,nums[i]);
        } 
        int ans = 0;
        for(int i = 0;i<nums.size();i++) {
            ans+=(nums[i] - minval);
        }
        return ans;
    }
};