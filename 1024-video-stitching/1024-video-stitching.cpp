class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(), clips.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] != b[0]) return a[0] < b[0];
            return a[1] > b[1];
        });
        int currEnd = 0;
        int farthest = 0;
        int count = 0;

        int i = 0;
        int n = clips.size();

        while (currEnd < time) {

            while (i < n && clips[i][0] <= currEnd) {
                farthest = max(farthest, clips[i][1]);
                i++;
            }

            if (farthest == currEnd) return -1;

            currEnd = farthest;
            count++;
        }

        return count;
    }
};