class Solution {
public:

    int countSetBits(int no) {
        int ans = 0;
        for(int i = 0;i<31;i++) {
            if((no & (1<<i)) != 0) ans++;
        }
        return ans;
    }
    
    int lower_bound(vector<int>& nums,int current,int k) {
        int left = 0;
        int right = nums.size();
        while(left<right) {
            int mid = left+(right-left)/2;
            if(countSetBits(current&nums[mid])+countSetBits(current | nums[mid]) >= k)  {
                right = mid;
            } else {
                left = mid+1;
            }
        }
        return left;
    }
    long long countExcellentPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end(),[this] (int a,int b) {
            if (countSetBits(a) != countSetBits(b)) {
                return countSetBits(a) < countSetBits(b);
            }
            return a < b;
        });
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        long long ans = 0;
        for(int i = 0;i<nums.size();i++) {
            int upper = lower_bound(nums,nums[i],k);
            ans += nums.size()-upper;
        }
        return ans;
    }

};