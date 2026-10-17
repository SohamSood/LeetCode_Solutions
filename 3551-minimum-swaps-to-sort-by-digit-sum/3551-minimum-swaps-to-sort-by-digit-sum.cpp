class Solution {
public: 
    vector<pair<int,int>> newarr;
    vector<bool> visited;
    int dfs(int index) {
        if(visited[index] == true) return 0;
        visited[index] = true;
        return dfs(newarr[index].second) + 1;
    }
    int digitsum(int a) {
        if(a == 0) return 0;
        return a%10+digitsum(a/10);
    }
    int minSwaps(vector<int>& nums) {
        newarr = vector<pair<int,int>>(nums.size());
        for(int i = 0;i<nums.size();i++) {
            newarr[i].first = digitsum(nums[i]); 
            newarr[i].second = i;
        }
        sort(newarr.begin(), newarr.end(), [&](const pair<int,int>& a, const pair<int,int>& b) {
            if (a.first == b.first)
                return nums[a.second] < nums[b.second];

            return a.first < b.first;
        });
        int ans = 0;
        visited = vector<bool> (nums.size(),false);
        for(int i = 0;i<newarr.size();i++) {
            if(visited[i] == false) {
                ans += dfs(i)-1;
            }
        }
        return ans;
    }
};