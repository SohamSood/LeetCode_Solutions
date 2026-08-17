class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        vector<vector<vector<int>>> dp(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(k+1,-1)));
        //dp will store maxsum;
        dp[0][0][k] = grid[0][0];
        for(int i = 0;i<grid.size();i++) {
            for(int j = 0;j<grid[0].size();j++) {
                int cost = 1;
                if(grid[i][j] == 0) cost = 0;
                if(i-1>=0) {
                    for(int kk = 0;kk<=k;kk++) {
                        if(dp[i-1][j][kk] != -1 && kk-cost >= 0) {
                            dp[i][j][kk-cost] = dp[i-1][j][kk] + grid[i][j];
                        }
                    }
                }
                if(j-1>=0) {
                    for(int kk = 0;kk<=k;kk++) {
                        if(dp[i][j-1][kk] != -1 && kk-cost >= 0) {
                            dp[i][j][kk-cost] = max(dp[i][j][kk-cost],dp[i][j-1][kk] + grid[i][j]);
                        }
                    }
                }
            }
        }
        int maxval = -1;
        for(int i = k;i>=0;i--) {
            if(dp.back().back()[i] != -1) {
                maxval = max(maxval,dp.back().back()[i]);
            }
        }
        return maxval;
    }
};