class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        vector<int> to_sort;
        for(int i = 0;i<score.size();i++) {
            to_sort.push_back(score[i][k]);
        }
        priority_queue<int, vector<int>, function<bool(int,int)>> pq(
            [&](int a, int b) {
                return to_sort[a] < to_sort[b];
            }
        );
        for(int i = 0;i<to_sort.size();i++){
            pq.push(i);
        }
        vector<int> order;
        while(!pq.empty()) {
            order.push_back(pq.top());
            pq.pop();
        }
        vector<vector<int>> ans(score.size(),vector<int>(score[0].size()));
        for(int i = 0;i<score.size();i++){
            for(int j = 0;j<score[i].size();j++) {
                ans[i][j] = score[order[i]][j];
            }
        }
        return ans;
    }
};