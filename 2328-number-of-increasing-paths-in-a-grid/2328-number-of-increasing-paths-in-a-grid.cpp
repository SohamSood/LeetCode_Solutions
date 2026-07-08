class Solution {
public:
    int dist = 0;
    int mod = 1e9+7;
    int dfs(vector<vector<int>>& grid,int i,int j,vector<vector<int>>& dp) {
        if(dp[i][j] != 0) {
            return dp[i][j];
        }
        int no = 1;

        if(i-1>=0 && grid[i][j]>grid[i-1][j]) {
            no = (no+dfs(grid,i-1,j,dp))%mod;
        }

        if(j-1>=0 && grid[i][j]>grid[i][j-1]) {
            no = (no+dfs(grid,i,j-1,dp))%mod;
        }

        if(i+1<grid.size() && grid[i][j]>grid[i+1][j]) {
            no = (no+dfs(grid,i+1,j,dp))%mod;
        }

        if(j+1<grid[0].size() && grid[i][j]>grid[i][j+1]) {
            no = (no+dfs(grid,i,j+1,dp))%mod;
        }
        dp[i][j] = no;
        return no;

    }
    int countPaths(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),0));
        for(int i = 0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                dist= (dist+dfs(grid,i,j,dp))%mod;
            }
        }
        return dist;
    }
};