class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<int>> visited(n,vector<int>(k+1.,INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<pair<int,int>>> adj(n);
        for(int i = 0;i<edges.size();i++) {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        visited[0][1] = 0;
        pq.push({0, 1, 0});
        while(!pq.empty()) {
            int curr_cost = pq.top()[0];
            int currk = pq.top()[1];
            int currnode = pq.top()[2];
            pq.pop();
            if(visited[currnode][currk] < curr_cost) continue;
            if(currnode == n-1) return curr_cost;
            for(pair<int,int>& p: adj[currnode]) {
                int newnode = p.first;
                int newcost = p.second+curr_cost;
                int newk = labels[currnode] == labels[newnode] ? currk+1 : 1;
                if(newk <= k && visited[newnode][newk] > newcost ) {
                    visited[newnode][newk] = newcost;
                    pq.push({newcost,newk,newnode});
                }
            }
        }
        return -1;
    }
};