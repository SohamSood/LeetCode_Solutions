class Solution {
public:
    int maximumSum(vector<int>& arr) {
        vector<int> dp(arr.size()); //with deletion
        vector<int> dp2(arr.size()); //without deletion
        dp2[0] = arr[0];
        dp[0] = arr[0];
        int ans = arr[0];
        for(int i = 1;i<arr.size();i++) {
            dp2[i] = max(arr[i],dp2[i-1] + arr[i]); // previous undeleted max(array starts from this element , previous undeleted + currentleement);
            dp[i] = max(dp2[i-1],dp[i-1]+arr[i]); // deleted max(current element is deleted , or previously any element was deleted we are simply continuing)
            ans = max(ans, max(dp[i], dp2[i]));
        }
        // for(int c:dp) cout<<c<<" ";
        // cout<<endl;
        // for(int c:dp2) cout<<c<<" "; 
        return ans;

    }
};