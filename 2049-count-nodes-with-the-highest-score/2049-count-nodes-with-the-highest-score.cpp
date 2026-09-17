class Solution {
public:
    vector<vector<int>> adj;
    long long maxi = 0;
    int count_of_maxi = 0;
    int dfs(int current) {
        long long product = 1;
        int no_of_nodes = 0;
        for(int i = 0;i<adj[current].size();i++)  { //processing child nodes;
            int count = dfs(adj[current][i]);
            no_of_nodes+=count;
            product = product*count;
        }
        if(current!=0) product *= (adj.size()-no_of_nodes-1);
        if(maxi == product) {
            count_of_maxi++;
        } else if(maxi < product){
            count_of_maxi = 1;
            maxi = product;
        }
        return no_of_nodes+1;
    }
    int countHighestScoreNodes(vector<int>& parents) {
        adj = vector<vector<int>>(parents.size());
        for(int i = 1;i<parents.size();i++) {
            adj[parents[i]].push_back(i);
        }
        int a = dfs(0);
        return count_of_maxi;
    }
};