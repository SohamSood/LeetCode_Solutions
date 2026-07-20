class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj(n);
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for(int i = 0;i<roads.size();i++) {
            adj[roads[i][0]].push_back(roads[i][1]);
            adj[roads[i][1]].push_back(roads[i][0]);
            dp[roads[i][0]][roads[i][1]] = true;
            dp[roads[i][1]][roads[i][0]] = true;
        }
        int maxcount = 0;
        for(int i = 0;i<adj.size();i++) {
            int count = adj[i].size();
            for(int j = i+1;j<adj.size();j++) {
                if(dp[i][j]) {
                    count--;
                }
                count+=adj[j].size();
                maxcount = max(maxcount,count);
                count = adj[i].size();
            }
        }
        return maxcount;
    }
};