class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        vector<int> dp(grid.size()*grid[0].size(),INT_MAX); //mincost to reach here 

        int ans = INT_MAX;
        for(int j = 0;j<grid[0].size();j++) {
            dp[grid[0][j]] = 0;
        }
        for(int i = 0;i<grid.size();i++) {
            for(int j = 0;j<grid[0].size();j++) {
                int currno = grid[i][j];
                if(i != grid.size()-1) {
                    for(int k = 0;k<grid[0].size();k++) {
                        dp[grid[i+1][k]] = min(dp[grid[i+1][k]],dp[currno] + moveCost[currno][k] + currno);
                    }
                } else {
                    ans = min(ans,dp[currno]+currno);
                }
                // cout<<dp[currno]<<" ";
            }
            // cout<<endl;
        }
        return ans;
    }
};