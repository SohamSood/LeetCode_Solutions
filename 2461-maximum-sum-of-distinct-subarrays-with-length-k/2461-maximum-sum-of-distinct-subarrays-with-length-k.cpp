class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sum = 0;
        long long curr_sum = 0;

        int start = 0;
        unordered_map<int,int> freq;
        for(int end = 0;end<nums.size();end++) {
            freq[nums[end]]++;
            curr_sum+=nums[end];
            while(freq[nums[end]]!=1 || end-start+1>k) {
                curr_sum -= nums[start];
                freq[nums[start]]--;
                start++;
            }
            if(end-start+1 == k) {
                sum = max(sum, curr_sum);
            }
        }
        return sum;
    }
};