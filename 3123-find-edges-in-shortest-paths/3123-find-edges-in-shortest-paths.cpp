class Solution {
public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> q;
        vector<vector<pair<int,int>>> adj(n);
        for(int i = 0;i<edges.size();i++) {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        vector<long long> dp(n,INT_MAX);
        dp[0] = 0;
        q.push({0,0});
        while(!q.empty()){
            int currnode = q.top().second;
            int currdist = q.top().first;
            q.pop();
            if(currdist > dp[currnode]) continue;
            for(int i = 0;i<adj[currnode].size();i++) {
                long long newdist = currdist + adj[currnode][i].second;
                int newnode = adj[currnode][i].first;
                if(newdist < dp[newnode]) {
                    dp[newnode] = newdist;
                    q.push({newdist,newnode});
                }
            }
        }
        vector<long long> dp2(n,INT_MAX);
        dp2[n-1] = 0;
        q.push({0,n-1});
        while(!q.empty()){
            int currnode = q.top().second;
            long long currdist = q.top().first;
            q.pop();
            if(currdist > dp2[currnode]) continue;
            for(int i = 0;i<adj[currnode].size();i++) {
                long long newdist = currdist + adj[currnode][i].second;
                int newnode = adj[currnode][i].first;
                if(newdist < dp2[newnode]) {
                    dp2[newnode] = newdist;
                    q.push({newdist,newnode});
                }
            }
        }
        vector<bool> ans(edges.size(),false);
        for(int i = 0;i<edges.size();i++) {
            if(dp[edges[i][0]] + dp2[edges[i][1]] + edges[i][2] == dp[dp.size()-1] || dp2[edges[i][0]] + dp[edges[i][1]] + edges[i][2] == dp[dp.size()-1]) {
                ans[i] = true;
            }
        }
        return ans;
    }
};