class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> dp(n,1);
        vector<int> pos(primes.size(),0);
        for(int j = 1;j<n;j++) {
            int minimum =  0;
            vector<int> currentMinimums = {0};
            for(int i = 1;i<pos.size();i++) {
                long long curr = 1LL * primes[i] * dp[pos[i]];
                long long minVal = 1LL * primes[minimum] * dp[pos[minimum]];
                if(curr<minVal) {
                    minimum = i;
                    currentMinimums.clear();
                    currentMinimums.push_back(i);
                } else if(curr == minVal) {
                    currentMinimums.push_back(i);
                }
            }
            dp[j] = primes[minimum]*dp[pos[minimum]];
            for(int x:currentMinimums) pos[x]++;
        }
        for(int x:dp) cout<<x<<" ";
        return dp.back();
    }
};