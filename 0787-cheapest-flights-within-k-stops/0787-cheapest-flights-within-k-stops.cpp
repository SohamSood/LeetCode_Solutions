class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i = 0;i<flights.size();i++) {
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        vector<vector<int>> dp(n,vector<int>(k+2,INT_MAX));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({0,k+1,src});
        dp[src][k+1] = 0;
        while(!pq.empty()) {
            int cost = pq.top()[0];
            int newk = pq.top()[1];
            int currnode = pq.top()[2];
            pq.pop();
            if(currnode == dst) return cost;
            if(newk == 0) continue;
            for(int i = 0;i<adj[currnode].size();i++) {
                if(cost + adj[currnode][i].second < dp[adj[currnode][i].first][newk-1]) {
                    dp[adj[currnode][i].first][newk-1] = cost+adj[currnode][i].second;
                    pq.push({cost+adj[currnode][i].second,newk-1,adj[currnode][i].first});
                }
            }
        }
        return -1;
    }
};