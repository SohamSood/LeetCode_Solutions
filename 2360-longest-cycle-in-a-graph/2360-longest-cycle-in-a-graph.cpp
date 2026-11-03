class Solution {
public:
    int maxvalue = -1;
    vector<int> ogvisited;
    vector<int> leaders;
    int currleader;
    void dfs(int currentno,int idx,vector<int>& edges) {
        if(idx == -1) return;
        if(ogvisited[idx] != -1) {
            if(leaders[idx] == currleader) {
                maxvalue = max(maxvalue,currentno-ogvisited[idx]);
            }
            return;
        }
        ogvisited[idx] = currentno;
        leaders[idx] = currleader;
        dfs(currentno+1,edges[idx],edges);
    }
    int longestCycle(vector<int>& edges) {
        ogvisited = vector<int>(edges.size(),-1);
        leaders = vector<int>(edges.size(),-1);
        vector<vector<int>> adj(edges.size());
        for(int i = 0;i<edges.size();i++) {
            if(ogvisited[i] != -1 || edges[i] == -1) {
                continue;
            }
            currleader = i;
            dfs(0,i,edges);
        }
        return maxvalue;
    }
};