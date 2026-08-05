class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> freq;
        unordered_map<int,int> freq2;
        for(int x:nums1) freq[x]++;
        for(int x:nums2) freq2[x]++;
        int count1 = 0;
        int count2 = 0;
        for(int x:nums2) if(freq[x] != 0) count1++;
        for(int x:nums1) if(freq2[x] != 0) count2++;
        return {count2,count1};
    }
};