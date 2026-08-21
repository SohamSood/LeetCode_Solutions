class Solution {
public:
    int intersect(vector<int>& a,vector<int>& b) {
       bool present[101] = {};
        for(int x : a) present[x] = true;
        int count = 0;

        for(int x : b) {
            if(present[x]) {
                count++;
                present[x] = false;
            }
        }

        return count;
    }
    void dfs(vector<vector<int>>& adj,vector<int>& leaders,int curr,int leader) {
        if(leaders[curr] != -1) return;
        leaders[curr]  = leader;
        for(int x: adj[curr]) dfs(adj,leaders,x,leader);
    }

    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n = properties.size();
        vector<vector<int>> adj(n);
        for(int i = 0;i<properties.size();i++) {
            for(int j = i+1;j<properties.size();j++) {
                if(intersect(properties[i],properties[j]) >= k) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> leaders(n,-1);
        int count = 0;
        for(int i = 0;i<n;i++) {
            if(leaders[i] == -1) {
                count++;
                dfs(adj,leaders,i,i);
            }
        } 
        return count;
    }
};