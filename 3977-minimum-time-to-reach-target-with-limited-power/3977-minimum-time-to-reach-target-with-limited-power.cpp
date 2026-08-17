class Solution {
public:
    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges, int power, vector<int>& cost, int source, int target) {
        if(source == target) {
            return {0,power};
        }
        vector<vector<pair<int,int>>> adj(n);
        //target , time
        for(int i = 0;i<edges.size();i++) {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        vector<vector<long long>> dp(n,vector<long long>(power+1,LLONG_MAX)); //mintime req to reach this k power 
        priority_queue<vector<long long>,vector<vector<long long>>,greater<vector<long long>>> pq;
        dp[source][power] = 0;
        pq.push({0,power,source});
        //currtime, currpower , currnode;
        long long min_time = -1;
        int max_power = -1;
        while(!pq.empty()) {
            long long curr_time = pq.top()[0];
            long long curr_power = pq.top()[1];
            long long curr_node = pq.top()[2];
            pq.pop();
            if(min_time != -1 && min_time < curr_time) break;
            if (curr_time != dp[curr_node][curr_power]) continue;
            if(curr_node == target) {
                if(min_time == -1) min_time = curr_time;
                max_power = max<long long>(max_power,curr_power);
                continue;
            } 
            long long new_power = curr_power - cost[curr_node];
            for(int i = 0;i<adj[curr_node].size();i++) {
                long long new_time = curr_time + adj[curr_node][i].second;
                long long new_node = adj[curr_node][i].first;
                if(new_power >= 0 && new_time < dp[new_node][new_power]) {
                    dp[new_node][new_power] = new_time;
                    pq.push({new_time,new_power,new_node});
                }
            }
        }
        if(min_time == -1) return {-1,-1};
        return {min_time,max_power};
    }
};