class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int element,int curr,vector<vector<int>>& adj,vector<bool>& visited){
        if(visited[curr] == true) {
            return;
        }
        visited[curr] = true;
        if(element != curr) ans[curr].push_back(element);
        for(int i = 0;i<adj[curr].size();i++) {
            dfs(element,adj[curr][i],adj,visited);
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        ans = vector<vector<int>>(n);
        for(int i = 0;i<edges.size();i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        for(int i = 0;i<n;i++) {
            vector<bool> visited(n,false);
            if(visited[i] == false) {
                dfs(i,i,adj,visited);
            }
        }
        return ans;
    }
};