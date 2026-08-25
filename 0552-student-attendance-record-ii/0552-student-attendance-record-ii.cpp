class Solution {
public:
    const int mod = 1e9+7;
    void dfs(int absent,int late,int n,vector<vector<vector<int>>>& dp) {
        
        //Present (Late resetting)
        dp[n][absent][0] = (dp[n-1][absent][late] + dp[n][absent][0])%mod;

        //Absent (Late resseting)
        if(absent - 1 >=0) {
            dp[n][absent][0] = (dp[n-1][absent-1][late]+ dp[n][absent][0])%mod;
        }

        //Late 
        if(late > 0) {
            dp[n][absent][late] = (dp[n][absent][late] + dp[n-1][absent][late-1]) % mod;
        }
    }
    int checkRecord(int n) {
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        //define dp state -> no of ways to reach with this value  
        //with these many absents and this consecutive values 
        //so current state depends on 
        dp[0][0][0] = 1;
        for(int i = 1;i<=n;i++) {
            for(int absent = 0;absent<2;absent++)  {
                for(int late = 0;late<3;late++) {
                    dfs(absent,late,i,dp);
                }
            }
        }
        int ans = 0;
        for(int absent = 0;absent<2;absent++)  {
            for(int late = 0;late<3;late++) {
                ans=(ans + dp[dp.size()-1][absent][late]) % mod; 
            }
        }
        return ans;
    }
};