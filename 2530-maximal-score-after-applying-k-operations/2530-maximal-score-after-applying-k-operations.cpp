class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;
        priority_queue<int> pq;
        for(int x:nums) pq.push(x);
        while(k > 0) {
            int a = pq.top();
            pq.pop();
            ans+=a;
            pq.push(ceil((double)a / 3));
            k--;
        }
        return ans;
    }
};