class Solution {
public:
    bool isPrintable(vector<vector<int>>& targetGrid) {
        vector<vector<int>> colors(61,{INT_MAX,INT_MAX,INT_MIN,INT_MIN});
        for(int i = 0;i<targetGrid.size();i++) {
            for(int j = 0;j<targetGrid[0].size();j++) {
                colors[targetGrid[i][j]][0] = min(colors[targetGrid[i][j]][0],i);
                colors[targetGrid[i][j]][1] = min(colors[targetGrid[i][j]][1],j);
                colors[targetGrid[i][j]][2] = max(colors[targetGrid[i][j]][2],i);
                colors[targetGrid[i][j]][3] = max(colors[targetGrid[i][j]][3],j);
            }
        }
        vector<unordered_set<int>> adj(61);
        for(int k = 0;k<colors.size();k++) {
            if(colors[k][0] == INT_MAX) continue;
            for(int i = colors[k][0];i<=colors[k][2];i++) {
                for(int j = colors[k][1];j<=colors[k][3];j++) {
                    if(targetGrid[i][j] != k) {
                        adj[k].insert(targetGrid[i][j]);
                    }
                }
            }
        }
        vector<int> indegree(61,0);
        for(int i = 0;i<adj.size();i++) {
            for(int x:adj[i]) indegree[x]++;
        }
        queue<int> q;
        for(int i = 0;i<indegree.size();i++) {
            if(colors[i][0] != INT_MAX && indegree[i]==0) q.push(i);
        }
        while(!q.empty()) {
            int current = q.front();
            q.pop();
            for(int x:adj[current]) {
                indegree[x]--;
                if(indegree[x] == 0) q.push(x);
            }
        }
        for(int x:indegree) if(x!=0) return false;
        return true;
    }
};