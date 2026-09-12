class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        //sliding window q where like minimize contiguos subarray of size -k to get the max ans 
        int total_sum = 0;

        int currsum = 0;
        int lowest_so_far = INT_MAX;

        int start = 0;
        for(int end = 0;end<nums.size();end++) {
            total_sum += nums[end];
            currsum+=nums[end];
            if(end-start+1 >= (nums.size()-k)) {
                lowest_so_far = min(lowest_so_far,currsum);
                currsum -= nums[start++];
            }
        }
        if(k == nums.size()) return total_sum; 
        return total_sum - lowest_so_far;
    }
};