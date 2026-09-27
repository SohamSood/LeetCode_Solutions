class Solution {
public:
    vector<int> leaders;
    vector<vector<int>> adj;
    void dfs(int current,int leader) {
        leaders[current] = leader;
        for(int x:adj[current]) {
            if(leaders[x] == -1) {
                dfs(x,leader);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1;
        leaders = vector<int>(n,-1);
        adj = vector<vector<int>>(n);
        for(int i = 0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        int total_components = 0;
        for(int i = 0;i<leaders.size();i++) {
            if(leaders[i] == -1) {
                total_components++;
                dfs(i,i);
            }
        }
        // cout<<total_components<<endl;
        // cout<<connections.size()<<endl;
        // if(connections.size() < n-1) return -1;
        // for(int i = 0;i<leaders.size();i++) cout<<i<<" "<<leaders[i]<<endl;
        return total_components - 1;
    }
};