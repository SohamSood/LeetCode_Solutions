class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        queue<int> q;
        q.push(id);
        int count = 0;
        unordered_map<string,int>freq;
        vector<bool> visited(friends.size(),false);
        visited[id] = true;
        while(!q.empty()) { 
            int size = q.size();
            for(int k = 0;k<size;k++) {
                int curr = q.front();
                q.pop();
                for(string x:watchedVideos[curr]) freq[x]++;
                for(int neighbours : friends[curr]) {
                    if(visited[neighbours] == true) continue;
                    visited[neighbours] = true;
                    q.push(neighbours);
                }
            }
            if(count == level) {
                break;
            } else {
                freq.clear();
            }
            count++;
        }
        vector<string> ans;

        for (auto &[video, frequency] : freq) {
            ans.push_back(video);
        }

        sort(ans.begin(), ans.end(), [&](string &a, string &b) {
            if (freq[a] != freq[b])
                return freq[a] < freq[b];
            return a < b;
        });
        return ans;
    }
};