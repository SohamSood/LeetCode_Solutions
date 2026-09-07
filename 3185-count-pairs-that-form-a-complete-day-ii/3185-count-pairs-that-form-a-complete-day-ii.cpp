class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        vector<int> dp(24,0);
        for(int x:hours) dp[x%24]++;
        // for(int i = 0;i<dp.size();i++) cout<<i<<" "<<dp[i]<<endl;
        long long ans = ((1LL * dp[0] * (dp[0]-1))/2)+((1LL * dp[12] * (dp[12]-1))/2);
        for(int i = 1;i<12;i++) {
            int a = dp[i];
            int b = dp[24-i];
            ans += (1LL*a*b);
        }
        return ans;
    }
};