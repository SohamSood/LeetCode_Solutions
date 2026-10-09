class Solution {
public:
    long long findScore(vector<int>& nums) {
        priority_queue<int, vector<int>, function<bool(int,int)>> pq(
            [&](int a, int b) {
                if(nums[a] == nums[b]) return a > b;
                return nums[a] > nums[b];
            }
        );
        for(int i = 0;i<nums.size();i++) pq.push(i);
        long long sum = 0;
        vector<bool> visited(nums.size(),false);
        while(!pq.empty()) {
            int a = pq.top();
            pq.pop();
            if(visited[a] == false) {
                sum+=nums[a];
                visited[a] = true;
                if(a-1>=0) visited[a-1] = true;
                if(a+1<visited.size()) visited[a+1] = true;
            }
        } 
        return sum;

    }
};