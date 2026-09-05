class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        //monotonic stack 
        vector<int> largest(nums.size(),0);
        vector<int> smallest(nums.size(),INT_MAX);

        smallest.back() = nums.back();
        largest[0] = nums[0];

        for(int i = 1;i<nums.size();i++)  largest[i] = max(largest[i-1],nums[i]);
        for(int i = nums.size()-2;i>=0;i--)  smallest[i] = min(smallest[i+1],nums[i]);


        for(int i = 0;i<nums.size();i++) {
            int stability_val = abs(largest[i] - smallest[i]);
            if(stability_val <= k) return i;
        }
        return -1;
    }
};