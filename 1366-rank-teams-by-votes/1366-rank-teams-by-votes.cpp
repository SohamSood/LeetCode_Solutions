class Solution {
public:
    string rankTeams(vector<string>& votes) {
        vector<vector<int>> myarr(26,vector<int>(votes[0].size() + 1,0));
        vector<bool> used(26,false); 
        for(int i = 0;i<votes.size();i++) {
            for(int j = 0;j<votes[i].size();j++) {
                used[votes[i][j] - 'A'] = true;
                myarr[votes[i][j] - 'A'][j]++;
            }
        }
        for(int i = 0;i<26;i++) {
            myarr[i].back() = -i;
        }
        priority_queue<vector<int>> pq;
        for(auto& p:myarr) pq.push(p);
        string ans;
        while(!pq.empty()) {
            int curr = -(pq.top().back());
            pq.pop();
            if(used[curr] == true) {
                ans.push_back(curr + 'A');
            }
        }
        return ans;
    }
};