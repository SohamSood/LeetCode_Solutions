class Solution {
public:
    vector<vector<int>> adj;
    vector<int> ans;
    void dfs(int curr) {
        if(ans[curr] != 0) return;
        vector<bool> canUse(4,false);
        for(int x : adj[curr]) {
            if(ans[x] != 0) {
                canUse[ans[x]-1] = true;
            }
        }
        for(int i = 0;i<4;i++){
            if(canUse[i] == false) {
                ans[curr] = i+1;
                break;
            }
        }
        // for(int x : adj[curr]) {
        //     dfs(x);
        // }
    }

    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        adj = vector<vector<int>>(n);
        ans = vector<int>(n,0);
        for(int i = 0;i<paths.size();i++) {
            paths[i][0]--;
            paths[i][1]--;
            adj[paths[i][0]].push_back(paths[i][1]);
            adj[paths[i][1]].push_back(paths[i][0]);
        }
        for(int i = 0;i<ans.size();i++) {
            if(ans[i] == 0) dfs(i);
        }
        return ans;
    }
};