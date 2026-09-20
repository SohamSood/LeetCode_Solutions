class BIT {
    vector<long long> bit;
    int n;

public:
    BIT(int n) {
        this->n = n;
        bit.resize(n + 2, 0);
    }

    void add(int idx, long long val) {
        for (; idx <= n; idx += idx & -idx) {
            bit[idx] += val;
        }
    }

    long long sum(int idx) {
        long long ans = 0;

        for (; idx > 0; idx -= idx & -idx) {
            ans += bit[idx];
        }

        return ans;
    }
};

class Solution {
public:
    vector<int> seq; //special dfs sequence
    vector<int> start; // start of the sequence
    vector<int> end; // end of the sequence
    vector<int> dist; //distance of root node from each node
    vector<int> ans; //answer array
    vector<vector<vector<int>>> adj; //  adjancy array 
    unordered_map<long long,int> freq; // tells which is parent of which element
    long long mod; 
    BIT* bit;


    void dfs(int parent,int current,int distance) {
        start[current] = seq.size();
        dist[current] = distance;
        seq.push_back(current);
        for(int i = 0;i<adj[current].size();i++) {
            if(adj[current][i][0] != parent) {
                int newcurrent = adj[current][i][0];
                freq[(current*mod)+newcurrent] = adj[current][i][1];
                dfs(current,adj[current][i][0],distance+adj[current][i][1]);
            }
        }
        end[current] = seq.size()-1;
    }

    void update(int u,int v,int newval) {
        if(freq.find(u*mod + v) == freq.end()) {
            swap(u,v);
        }
        int difference = newval - freq[u*mod + v];
        freq[u*mod + v]  = newval;
        bit->add(start[v]+1, difference);
        bit->add(end[v]+2, -difference);
    }
    
    vector<int> treeQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        bit = new BIT(n);
        adj = vector<vector<vector<int>>>(n+1);
        start = vector<int>(n+1);
        end= vector<int>(n+1);
        dist = vector<int>(n+1);
        mod = 1000000;


        for(int i = 0;i<edges.size();i++) {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        dfs(-1,1,0);
        
        for(int i = 0;i<queries.size();i++) {
            if(queries[i][0] == 1) {
                update(queries[i][1],queries[i][2],queries[i][3]);
            } else {
                int x = queries[i][1];
                ans.push_back(dist[x] + bit->sum(start[x] + 1));
            }
        }
        return ans;
    }
};