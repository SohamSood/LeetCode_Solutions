class Solution {
public:
    int find(int currnode,vector<int>& root) {
        if(currnode == root[currnode]) return currnode;
        root[currnode] = find(root[currnode],root);
        return root[currnode];
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> root(edges.size()+1);
        for(int i = 0;i<root.size();i++) {
            root[i] = i;
        }
        int ans = 0;
        int u,v;
        for(int i = 0;i<edges.size();i++) {
            u = edges[i][0];
            v = edges[i][1];
            if(find(u,root) == find(v,root)) {
                //same component;
                ans = i;
            } else {
                root[find(v,root)] = find(u,root); 
                // merge(u,v);
            }
        }
        return edges[ans];
    }
};