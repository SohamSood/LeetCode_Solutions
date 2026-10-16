class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> myarr(nums.size());
        for(int i = 0;i<nums.size();i++){
            myarr[i] = nums[nums[i]];
        }
        return myarr;
    }
};