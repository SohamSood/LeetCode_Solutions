class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj(n);
        for(int i = 0;i<roads.size();i++) {
            adj[roads[i][0]].push_back(roads[i][1]);
            adj[roads[i][1]].push_back(roads[i][0]);
        }
        int maxcount = 0;
        for(int i = 0;i<adj.size();i++) {
            unordered_set<int> freq;
            for(int x:adj[i]) freq.insert(x);
            int count = freq.size();
            for(int j = i+1;j<adj.size();j++) {
                if(freq.find(j) != freq.end()) {
                    count--;
                }
                count+=adj[j].size();
                maxcount = max(maxcount,count);
                count = freq.size();
            }
            maxcount = max(maxcount,count);
        }
        return maxcount;
    }
};