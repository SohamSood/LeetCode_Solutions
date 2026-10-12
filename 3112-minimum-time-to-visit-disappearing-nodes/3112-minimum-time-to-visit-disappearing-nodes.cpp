class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i = 0;i<edges.size();i++) {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> visited(n,-1);
        visited[0] = 0;
        pq.push({0,0});

        while(!pq.empty()) {
            int currtime = pq.top().first;
            int currnode = pq.top().second;
            pq.pop();
            if(visited[currnode] != currtime) continue;
            for(int i = 0;i<adj[currnode].size();i++) {
                int child = adj[currnode][i].first;
                int newtime= currtime + adj[currnode][i].second;
                if(newtime >= disappear[child]) continue; 
                if(newtime>= visited[child] && visited[child] != -1) continue;
                pq.push({newtime,child});
                visited[child] = newtime;
            }
        }
        return visited;
    }
};