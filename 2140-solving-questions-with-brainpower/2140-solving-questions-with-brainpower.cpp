class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size(),0);
        long long maxans=questions[0][0];
        for(int i = 0;i<questions.size();i++) {
            int currentpower = questions[i][0];
            int nextvalue = questions[i][1];
            if(i+1 < questions.size()) {
                dp[i+1] = max(dp[i+1],dp[i]);
            }
            dp[i] += currentpower;
            if(i+nextvalue+1 < questions.size()) {
                dp[i+nextvalue+1] = max(dp[i+nextvalue+1],dp[i]);
            }
            maxans = max(maxans,dp[i]);
        }
        // for(long long x:dp) cout<<x<<endl;
        return maxans;
    }
};