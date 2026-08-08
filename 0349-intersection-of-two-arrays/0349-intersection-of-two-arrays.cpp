class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> nums11;
        unordered_set<int> nums22;
        for(int x:nums1) nums11.insert(x);
        for(int x:nums2) nums22.insert(x);
        vector<int> ans;
        for(int x:nums11) {
            if(nums22.find(x) != nums22.end()) ans.push_back(x);
        }
        return ans;
    }
};