class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        vector<vector<pair<int,int>>> dp(grid.size(), vector<pair<int,int>>(grid[0].size(), {0,0}));

        dp[0][0] = {1,0};

        int mod = 1e9+7;

        // {left,up}
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {

                if(grid[i][j] == 1) {
                    if(i+1 < grid.size()) {
                        dp[i+1][j].second = (dp[i+1][j].second + dp[i][j].first) % mod;
                    }

                    if(j+1 < grid[0].size()) {
                        dp[i][j+1].first = (dp[i][j+1].first + dp[i][j].second) % mod;
                    }

                    continue;
                }

                int total = (dp[i][j].first + dp[i][j].second) % mod;

                if(i+1 < grid.size()) {
                    dp[i+1][j].second = (dp[i+1][j].second + total) % mod;
                }

                if(j+1 < grid[0].size()) {
                    dp[i][j+1].first = (dp[i][j+1].first + total) % mod;
                }
            }
        }

        return (dp.back().back().first + dp.back().back().second) % mod;
    }
};