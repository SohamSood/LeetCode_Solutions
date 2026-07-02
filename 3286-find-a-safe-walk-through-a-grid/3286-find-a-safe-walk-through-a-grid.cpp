class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
        priority_queue<pair<int,pair<int,int>>> pq;
        
        if(grid[0][0] == 0) pq.push({health,{0,0}});
        else pq.push({health-1,{0,0}});
        while(!pq.empty()){
            int curr = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            if(curr<=0) continue;
            if(curr <= visited[x][y]) {
                continue;
            }
            if(x == grid.size()-1 && y == grid[0].size()-1) return true;
            visited[x][y] = curr;

            if(x-1 >= 0) {
                if(grid[x-1][y] == 1) {
                    pq.push({curr-1,{x-1,y}});
                } else{
                    pq.push({curr,{x-1,y}});
                }
            }
            if(y-1>=0) {
                if(grid[x][y-1] == 1) {
                    pq.push({curr-1,{x,y-1}});
                } else{
                    pq.push({curr,{x,y-1}});
                }
            }
            if(x+1<grid.size()) {
                if(grid[x+1][y] == 1) {
                    pq.push({curr-1,{x+1,y}});
                } else{
                    pq.push({curr,{x+1,y}});
                }
            }
            if(y+1 < grid[0].size()){
                if(grid[x][y+1] == 1) {
                    pq.push({curr-1,{x,y+1}});
                } else{
                    pq.push({curr,{x,y+1}});
                }
            }
        }
        return false;
    }
};