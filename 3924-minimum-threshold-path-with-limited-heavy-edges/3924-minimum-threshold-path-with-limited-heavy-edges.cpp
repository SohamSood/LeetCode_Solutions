class Solution {
public:
    bool pathexists(int n,int source,int target,vector<vector<vector<int>>>& adj,int k,int threshold) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        vector<int> dist(n, INT_MAX);
        dist[source] = 0;
        pq.push({0,source});
        while(!pq.empty()) {
            int cost = pq.top()[0];
            int curr = pq.top()[1];
            pq.pop();
            if (cost > dist[curr]) continue;
            if (curr == target) {
                return cost <= k;
            }
            for(int i = 0;i<adj[curr].size();i++) {
                int next = adj[curr][i][0];
                int newCost = cost + (adj[curr][i][1] > threshold);
                if (newCost < dist[next]) {
                    dist[next] = newCost;
                    pq.push({newCost, next});
                }
            }      
        }
        return false;
    }
    int minimumThreshold(int n, vector<vector<int>>& edges, int source, int target, int k) {
        int left = 0;
        int right = 0;
        int ans = -1;
        vector<vector<vector<int>>> adj(n);
        for(int i = 0;i<edges.size();i++)  {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});

            right = max(right,edges[i][2]);
        } 
        while(left <= right) {
            int mid = left+(right-left)/2;
            if(pathexists(n,source,target,adj,k,mid)) {
                ans = mid;
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        return ans;
    }
};