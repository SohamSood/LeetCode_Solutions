class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        if(n == 1) return 1;
        vector<vector<pair<int,int>>> adj(n+1);
        vector<bool> visited(n);
        int minval = INT_MAX;
        for(int i = 0;i<roads.size();i++) {
            minval = min(minval,roads[i][2]);
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        int mini = INT_MAX;
        queue<pair<int,int>> q;
        q.push({1,INT_MAX});
        while(!q.empty()) {
            int a = q.front().first;
            int b = q.front().second;
            mini = min(mini,b);
            if(mini == minval) return mini;
            q.pop();
            if(visited[a] == true) continue;
            visited[a] = true; 
            for(int i = 0;i<adj[a].size();i++) {
                q.push({adj[a][i].first,adj[a][i].second});
            }
        }
        return mini;
    }
};