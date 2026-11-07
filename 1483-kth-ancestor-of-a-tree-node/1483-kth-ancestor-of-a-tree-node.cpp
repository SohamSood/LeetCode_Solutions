class TreeAncestor {
public:
    vector<vector<int>>dp;
    TreeAncestor(int n, vector<int>& parent) {
        dp = vector<vector<int>>(n,vector<int>(ceil(log2(n)) + 1,-1));
        for(int i = 0;i<parent.size();i++) {
            dp[i][0] = parent[i];
        }
        for(int k = 1;k<dp[0].size();k++){
            for(int i = 0;i<dp.size();i++) {
                int previous_ancestor = dp[i][k-1];
                if(previous_ancestor == -1) continue;
                int ans = dp[previous_ancestor][k-1];
                dp[i][k] = ans;
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int i = 31;i>=0;i--) {
            if((k & (1<<i)) != 0) {
                node = dp[node][i];
                if(node == -1) return -1;
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */