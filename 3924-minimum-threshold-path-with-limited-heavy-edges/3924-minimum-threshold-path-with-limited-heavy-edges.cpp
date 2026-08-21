class Solution {
public:
    bool pathexists(int n,int source,int target,vector<vector<vector<int>>>& adj,int k,int threshold) {
        deque<int> dq;
        vector<int> dist(n, INT_MAX);
        dist[source] = 0; 
        dq.push_back(source);
        while(!dq.empty()) {
            int currnode = dq.front();
            dq.pop_front();
            if(currnode == target) return dist[currnode] <= k;
            for(int i = 0;i<adj[currnode].size();i++) {
                int next = adj[currnode][i][0];
                int weight = adj[currnode][i][1];
                int heavy = 0;
                if(weight>threshold) {
                    heavy = 1;
                } 
                int newcost = dist[currnode] + heavy;

                if(newcost < dist[next]) {
                    dist[next] = newcost;
                    if(heavy == 0) {
                        dq.push_front(next);
                    } else {
                        dq.push_back(next);
                    }
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