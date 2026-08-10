class Solution {
public:
    bool dfs(vector<vector<int>>& grid,int i,int j) {
        if(i>=grid.size() || j>=grid[0].size()) return false;
        if(grid[i][j] == 0) return false;
        if(i == grid.size()-1 && j == grid[0].size()-1) return true;
        grid[i][j] = 0;
        return dfs(grid,i+1,j) || dfs(grid,i,j+1);

    }
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        dfs(grid,0,0);
        grid[0][0] = 1;
        grid[grid.size()-1][grid[0].size()-1] = 1;
        return !dfs(grid,0,0);
    }
};