class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        vector<bool> rows(grid.size(),0);
        vector<bool> cols(grid[0].size(),0);
        int rowstart = -1;
        int rowend = -1;
        int colstart = -1;
        int colend = -1;
        for(int i = 0;i<grid.size();i++) {
            for(int j = 0;j<grid[0].size();j++) {
                if(grid[i][j] == 1) {
                    if(rowstart == -1) {
                        rowstart = i;
                    }
                    if(colstart == -1  || colstart > j) {
                        colstart = j;
                    }
                    rowend = max(i,rowend);
                    colend = max(j,colend);
                }
            }
        }
        return (rowend-rowstart+1) * (1+colend-colstart);
    }
};