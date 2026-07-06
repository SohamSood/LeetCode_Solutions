class Solution {
public:
    bool match(vector<vector<int>>& intervals,int previous,int end) {
        if ((intervals[previous][0] <= intervals[end][0]) && (intervals[previous][1] >= intervals[end][1])) {
            return true;
        }
        return false;
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
            if (a[0] == b[0])
                return a[1] > b[1]; 
            return a[0] < b[0];      
        });
        
        int previous = 0;
        int count = 0;
        for(int i = 1;i<intervals.size();i++) {
            if(match(intervals,previous,i)) {
                count++;
                // cout<<intervals[previous][0]<<" "<<intervals[previous][1]<<" , "<<intervals[i][0]<<" "<<intervals[i][1]<<endl;
            } else {
                previous = i;
            }
        }
        return intervals.size() - count;
    }
};