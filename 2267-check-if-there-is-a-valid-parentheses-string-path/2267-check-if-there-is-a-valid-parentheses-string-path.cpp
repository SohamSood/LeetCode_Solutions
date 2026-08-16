class Solution {
public:
    vector<vector<vector<bool>>> dp;
    void validpaths(int i, int j, char s) {
        if(i-1>=0) {
            if (s == '(') {
                for (int k = 0; k < 99; k++) {
                    if (dp[i-1][j][k] == true) {
                        dp[i][j][k+1] = true;
                    }
                }
            } else {
                for (int k = 1; k < 100; k++) {
                    if (dp[i-1][j][k] == true) {
                        dp[i][j][k-1] = true;
                    }
                }
            }
        }
        if(j-1>=0) {
            if (s == '(') {
                for (int k = 0; k < 99; k++) {
                    if (dp[i][j-1][k] == true) {
                        dp[i][j][k+1] = true;
                    }
                }
            } else {
                for (int k = 1; k < 100; k++) {
                    if (dp[i][j-1][k] == true) {
                        dp[i][j][k-1] = true;
                    }
                }
            }
        }
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        if (grid[0][0] == ')' || grid.back().back() == '(') return false;
        dp = vector<vector<vector<bool>>>(grid.size(),vector<vector<bool>>(grid[0].size(),vector<bool>(101, 0)));
        dp[0][0][1] = 1;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                validpaths(i,j,grid[i][j]);
            }
        }
        return dp.back().back()[0];
    }
};