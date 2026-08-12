class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> freq; 
        int start = 0;
        int maxlen = 1;
        for(int end = 0;end<nums.size();end++) {
            freq[nums[end]]++;
            while(start < end && freq[nums[end]] > k) {
                freq[nums[start++]]--;
            }
            maxlen = max(maxlen,end-start+1);
        }
        return maxlen;
    }
};