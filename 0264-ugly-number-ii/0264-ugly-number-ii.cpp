class Solution {
public:
    int nthUglyNumber(int n) {
        unordered_set<int> st;
        priority_queue<int,vector<int>,greater<int>> pq;
        pq.push(1);
        while(!pq.empty()) {
            int a = pq.top();
            pq.pop();
            if(st.find(a) == st.end()) {
                st.insert(a);
                n--;
                if(n == 0) return a;
                if(a < INT_MAX/2) pq.push(2*a);
                if(a < INT_MAX/3) pq.push(3*a);
                if(a < INT_MAX/5) pq.push(5*a);
            }
        }
        return 0;
    }
};