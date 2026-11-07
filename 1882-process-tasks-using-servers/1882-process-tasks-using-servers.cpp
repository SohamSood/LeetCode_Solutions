class Solution {
public:
    struct Compare {
        vector<int>& servers;

        Compare(vector<int>& s) : servers(s) {}

        bool operator()(int a, int b) {
            if (servers[a] == servers[b]) {
                return a > b;
            }
            return servers[a] > servers[b];
        }
    };
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<int, vector<int>, Compare> pq{Compare(servers)};
        for (int i = 0; i < servers.size(); i++) {
            pq.push(i);
        }
        vector<int> ans;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> busy;
        long long currtime = 0;
        for(int i = 0;i<tasks.size();i++)  {
            if(pq.empty()) {
                long long newtime = busy.top().first;
                currtime = newtime;
                pq.push(busy.top().second);
                busy.pop();
            }
            while(!busy.empty() && busy.top().first <= currtime) {
                pq.push(busy.top().second);
                busy.pop();
            } 
            ans.push_back(pq.top());
            busy.push({currtime+tasks[i],pq.top()});
            pq.pop();
            if(currtime == i) currtime++;
        }
        return ans;
    }
};