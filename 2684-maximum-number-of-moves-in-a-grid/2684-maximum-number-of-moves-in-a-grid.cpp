class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),0));
        for(int i = 0;i<grid.size();i++) dp[i][0] = 1;
        int ans = 0;
        for(int j = 1;j<grid[0].size();j++) {
            for(int i = 0;i<grid.size();i++) {
                if(grid[i][j] > grid[i][j-1] && dp[i][j-1] != 0) {
                    dp[i][j] = max(dp[i][j],dp[i][j-1]+1);
                }
                if(i-1>=0 && grid[i][j] > grid[i-1][j-1] && dp[i-1][j-1] != 0) {
                    dp[i][j] = max(dp[i][j],dp[i-1][j-1]+1);
                }
                if(i+1<grid.size() && grid[i][j] > grid[i+1][j-1] && dp[i+1][j-1] != 0) {
                    dp[i][j] = max(dp[i][j],dp[i+1][j-1]+1);
                }
                ans = max(dp[i][j],ans);
            }
        }
        // for(int i = 0;i<grid.size();i++) {
        //     for(int j = 0;j<grid[0].size();j++) {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return ans == 0 ? 0 : ans-1;
    }
};