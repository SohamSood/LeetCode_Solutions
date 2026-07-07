class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<long long>visited(n,LLONG_MAX);
        vector<long long> ways(n,0);
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> q;
        vector<vector<pair<long long,long long>>> adj(n);
        for(int i = 0;i<roads.size();i++) {
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        int MOD = 1e9 + 7;
        q.push({0,0});
        ways[0] = 1;
        visited[0]=0;
        int count = 0;
        int thattime = 0;
        while(!q.empty()) {
            long long time = q.top().first;
            int currnode = q.top().second;
            if(currnode == n-1) {
                if(count == 0) {
                    thattime = time;
                    count = (count+ways[currnode]) % MOD;
                }
                else if(thattime == time) count = (count+ways[currnode])%MOD;
            }
            if(count!=0 && time > thattime) {
                break;
            }
            q.pop();
            if(time > visited[currnode]) continue;
            for(auto p:adj[currnode]) {
                long long newtime = p.second+time;
                int newnode = p.first;
                if(visited[newnode] > newtime) {
                    visited[newnode] = newtime;
                    ways[newnode]=  ways[currnode];
                    q.push({newtime,newnode});
                } else if(visited[newnode] == newtime) {
                    ways[newnode]= (ways[newnode] + ways[currnode]) % MOD;
                }
            }
        }
        return count;
    }
};