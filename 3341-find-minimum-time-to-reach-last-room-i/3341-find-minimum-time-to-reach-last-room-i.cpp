class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<vector<int>> visited(moveTime.size(),vector<int>(moveTime[0].size(),INT_MAX));
        visited[0][0] = moveTime[0][0];

        pq.push({0,0});

        while(!pq.empty()) {
            int currentTime = pq.top().first;

            int x = pq.top().second % 50;
            int y = pq.top().second / 50;

            if(x == moveTime.size()-1 && y == moveTime[0].size()-1) {
                return max(currentTime,moveTime[x][y]);
            }
            pq.pop();
            if(x-1 >= 0) {
                int bestTime = 1+ max(currentTime , moveTime[x-1][y]);
                if(bestTime < visited[x-1][y]) {
                    visited[x-1][y] = bestTime;
                    pq.push({bestTime, y*50 + (x-1)});
                }
            }
            if(y-1 >= 0) {
                int bestTime = 1+max(currentTime , moveTime[x][y-1]);
                if(bestTime < visited[x][y-1]) {
                    visited[x][y-1] = bestTime;
                    pq.push({bestTime, (y-1)*50 + x});
                }
            }
            if(x+1 < moveTime.size()) {
                int bestTime = 1+max(currentTime , moveTime[x+1][y]);
                if(bestTime < visited[x+1][y]) {
                    visited[x+1][y] = bestTime;
                    pq.push({bestTime, y*50 + (x+1)});
                }

            }
            if(y+1 < moveTime[0].size()) {
                int bestTime = 1+max(currentTime , moveTime[x][y+1]);
                if(bestTime < visited[x][y+1]) {
                    visited[x][y+1] = bestTime;
                    pq.push({bestTime, (y+1)*50 + x});
                }
            }
        }
        return 0;
    }
};