class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int g = coins[0];
        for (int c : coins) g = gcd(g, c);
        if (amount % g != 0) return 0;
        vector<unsigned long long> dp(amount+1,0);
        dp[0] = 1;
        for(int j = 0;j<coins.size();j++) {
            for(int i = coins[j];i<=amount;i++) {
                dp[i]+=dp[i-coins[j]];
            }
        }
        return dp.back();
    }
};