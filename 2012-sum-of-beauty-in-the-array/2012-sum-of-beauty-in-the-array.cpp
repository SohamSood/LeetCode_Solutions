class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();

        vector<bool> isValid(n, true);

        int currmin = nums.back();

        for(int i = n - 2; i > 0; i--) {
            if(nums[i] >= currmin) {
                isValid[i] = false;
            }
            currmin = min(currmin, nums[i]);
        }

        int currmax = nums[0];

        for(int i = 1; i < n - 1; i++) {
            if(nums[i] <= currmax) {
                isValid[i] = false;
            }
            currmax = max(currmax, nums[i]);
        }

        int ans = 0;

        for(int i = 1; i < n - 1; i++) {
            if(isValid[i]) {
                ans += 2;
            }
            else if(nums[i - 1] < nums[i] && nums[i] < nums[i + 1]) {
                ans++;
            }
        }

        return ans;
    }
};