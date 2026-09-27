class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        priority_queue<pair<double,int>,vector<pair<double,int>>> pq;
        pq.push({1.0,start_node});
        vector<double> maxprob(n,INT_MIN);
        maxprob[start_node] = 1.0;
        vector<vector<pair<int,double>>> adj(n);
        for(int i = 0;i<edges.size();i++) {
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        while(!pq.empty()) {
            double currprob = pq.top().first;
            int currnode = pq.top().second;
            pq.pop();
            
            if(currnode == end_node) return currprob;
           
            for(int i = 0;i<adj[currnode].size();i++) {
                int newnode = adj[currnode][i].first;
                double newprob = adj[currnode][i].second  * currprob;
                if(newprob > maxprob[newnode]) {
                    maxprob[newnode] = newprob;
                    pq.push({newprob,newnode});
                }
            }
        }
        return 0;
    }
};