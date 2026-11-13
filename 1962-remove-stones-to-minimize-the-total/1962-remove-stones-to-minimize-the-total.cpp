class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        int sum = 0;
        for(int x:piles) {
            pq.push(x);
            sum+=x;
        }
        while(k != 0) {
            int a = pq.top();
            pq.pop();
            pq.push(a-a/2);
            sum = sum - a/2;
            k--;
        }
        return sum;
    }
};