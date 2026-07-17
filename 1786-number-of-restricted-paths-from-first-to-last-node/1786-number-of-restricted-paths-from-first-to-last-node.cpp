class Solution {
public:
    int mod = 1e9+ 7;
    int dfs(int currnode, vector<vector<pair<int,int>>>& adj,vector<int>& dp,int n,vector<int>& dp2) {
        if(currnode == n) {
            return 1;
        }
        if (dp2[currnode] != -1) return dp2[currnode];
        int ans = 0;
        for(int i = 0;i<adj[currnode].size();i++) {
            if(dp[currnode] > dp[adj[currnode][i].first]) {
                if(dp2[adj[currnode][i].first] == -1) {
                    dp2[adj[currnode][i].first] = dfs(adj[currnode][i].first,adj,dp,n,dp2);
                }
                ans=(dp2[adj[currnode][i].first]+ans)%mod;
            }
        }
        return ans;
    }
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i = 0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        pq.push({0,n});
        vector<int> dp(n+1,INT_MAX);
        dp[n] = 0; 
        while(!pq.empty()) {
            int currnode = pq.top().second;
            int currdist = pq.top().first;
            pq.pop();
            for(int i = 0;i<adj[currnode].size();i++) {
                if(dp[adj[currnode][i].first] > adj[currnode][i].second + currdist ) {
                    dp[adj[currnode][i].first] = adj[currnode][i].second + currdist;
                    pq.push({adj[currnode][i].second + currdist,adj[currnode][i].first});
                }
            }
        }
        vector<int> dp2(n+1,-1);
        return dfs(1,adj,dp,n,dp2);
    }
};