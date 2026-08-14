class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        vector<vector<vector<bool>>> dp(grid.size(),vector<vector<bool>>(grid[0].size(),vector<bool>(1024,0)));
        dp[0][0][grid[0][0]] = true; 
        for(int i = 0;i<grid.size();i++) {
            for(int j = 0;j<grid[0].size();j++) {
                if(i-1>=0) {
                    for(int k = 0;k<1024;k++) {
                        if(dp[i-1][j][k] == true) {
                            dp[i][j][k ^ grid[i][j]] = true;
                        }
                    }
                }
                if(j-1>=0) {
                    for(int k = 0;k<1024;k++){
                        if(dp[i][j-1][k] == true) {
                            dp[i][j][k ^ grid[i][j]] = true;
                        }
                    }
                }   
            }
        }
        for(int k = 0;k<1024;k++) {
            if(dp[dp.size()-1][dp[0].size()-1][k] == true) {
                return k;
            }
        }
        return 0;
    }
};
