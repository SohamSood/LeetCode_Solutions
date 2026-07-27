class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1,0);
        for(int i = 1;i<=n;i++) {
            dp[i] = dp[(i>>1)];
            if(i%2 == 1) dp[i]++;
        }
        return dp;
    }
};