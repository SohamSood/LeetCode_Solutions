class Graph {
public:
    int nn = 0;
    vector<vector<pair<int,int>>> adj;
    Graph(int n, vector<vector<int>>& edges) {
        adj = vector<vector<pair<int,int>>>(n);
        nn = n;
        for(int i = 0;i<edges.size();i++) {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,node1});
        vector<int> dp(nn,INT_MAX);
        dp[node1] = 0;
        while(!pq.empty()) {
            int currnode = pq.top().second;
            int currdist = pq.top().first;
            pq.pop();
            if (currdist > dp[currnode]) {
                continue;
            }
            if(currnode == node2) return currdist;
            for(int i = 0;i<adj[currnode].size();i++) {
                if(dp[adj[currnode][i].first] > adj[currnode][i].second + currdist ) {
                    dp[adj[currnode][i].first] = adj[currnode][i].second + currdist;
                    pq.push({adj[currnode][i].second + currdist,adj[currnode][i].first});
                }
            }
        }
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */