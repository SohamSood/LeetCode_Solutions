class Solution {
public:
    vector<unordered_set<int>> adj;
    vector<int> odd;
    bool check(int a,int b,int param) {
        if (!adj[a].count(b)) return true;
        if(param == 4) return false;
        for(int i = 1;i<adj.size();i++) {
            if(i == a || i == b) continue;
            if(!adj[i].count(a) && !adj[i].count(b)) return true;
        }
        return false;
    }
    bool isPossible(int n, vector<vector<int>>& edges) {
        adj = vector<unordered_set<int>>(n + 1);
        odd.clear();
        for(int i = 0;i<edges.size();i++) {
            adj[edges[i][0]].insert(edges[i][1]);
            adj[edges[i][1]].insert(edges[i][0]);
        }
        for(int i = 1;i<=n;i++) {
            if(adj[i].size() % 2 != 0) odd.push_back(i);
        }

        if(odd.size() == 0) return 1;
        if(odd.size() != 2 && odd.size() != 4) return 0;
        if(odd.size() == 2) {
            return check(odd[0],odd[1],2);
        }
        if(odd.size() == 4) {
            if(check(odd[0],odd[1],4) && check(odd[2],odd[3],4)) return true;
            if(check(odd[0],odd[2],4) && check(odd[3],odd[1],4)) return true;
            if(check(odd[0],odd[3],4) && check(odd[1],odd[2],4)) return true;
        }
        return 0;
    }
};