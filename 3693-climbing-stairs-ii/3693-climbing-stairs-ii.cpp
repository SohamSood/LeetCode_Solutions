class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for(int i = 0; i < n; i++) {
            if(i + 1 <= n)  dp[i+1] = min(dp[i+1], costs[i] + 1 + dp[i]);
            if(i + 2 <= n) dp[i+2] = min(dp[i+2], costs[i+1] + 4 + dp[i]);
            if(i + 3 <= n) dp[i+3] = min(dp[i+3], costs[i+2] + 9 + dp[i]);
        }
        return dp[n];
    }
};