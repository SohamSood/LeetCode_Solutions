class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,vector<int>> freq;
        for(int i = 0;i<nums.size();i++) {
            freq[nums[i]].push_back(i);
            if (freq[nums[i]].size() >= 2 && freq[nums[i]][freq[nums[i]].size()-1] - freq[nums[i]][freq[nums[i]].size()-2] <= k) return true;
        }
        return false;
    }
};