class Solution {
public:
    vector<vector<int>> dp = vector<vector<int>>(8, vector<int>(1024, -1));
    int backtracking(int remaining,int mask){
        if(remaining == 0) return 1;
        if(dp[remaining][mask] != -1) return dp[remaining][mask]; 
        int count = 0;

        for(int i = 0;i<=9;i++) {
            if((mask & (1<<i)) == 0){
                count+=backtracking(remaining-1,mask|(1<<i));
            }
        }

        dp[remaining][mask] = count;
        return count;
    }
    int countNumbersWithUniqueDigits(int n) {
         int count = 1;
        for (int len = 1; len <= n; len++) {
            for (int d = 1; d <= 9; d++) {
                count += backtracking(len - 1, 1 << d);
            }
        }
        return count;
    }
};