class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int zero_count = (nums[0] == 0);
        int XOR = nums[0];
        for(int i = 1;i<nums.size();i++){ 
            XOR = XOR^nums[i];
            if(nums[i] == 0) zero_count++;
        } 
        if(zero_count == nums.size()) return 0;
        if(XOR != 0) return nums.size();
        return nums.size()-1;
    }
};