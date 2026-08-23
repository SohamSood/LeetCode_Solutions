class Solution {
public:
    struct Compare {
        bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
            if (a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        }
    };
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        unordered_set<string> positivewords;
        unordered_set<string> negativewords;
        for(string x:positive_feedback) positivewords.insert(x);
        for(string x:negative_feedback) negativewords.insert(x);
        vector<int> marks(student_id.size(),0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,Compare> pq;
        for(int i = 0;i<report.size();i++) {
            stringstream ss(report[i]);
            string word;
            while (ss >> word) {
                if(positivewords.find(word) != positivewords.end()) {
                    marks[i]+=3;
                } else if(negativewords.find(word) != negativewords.end()) {
                    marks[i]-=1;
                }
            }
        }
        for(int i = 0;i<marks.size();i++) {
            pq.push({marks[i],student_id[i]});
        }
        vector<int> ans;
        int times = 0;
        while(!pq.empty() && times<k) {
            // cout<<pq.top().first << " "<<pq.top().second<<endl;
            ans.push_back(pq.top().second);
            times++;
            pq.pop();
        }
        return ans;
    }
};