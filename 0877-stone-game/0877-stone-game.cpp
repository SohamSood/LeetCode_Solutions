class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        vector<vector<int>> dp(piles.size(),vector<int>(piles.size(),0));
        for(int i = 0;i<piles.size();i++) {
            dp[i][i] = piles[i];
        }
        for(int i = 1;i<piles.size();i++){
            for(int start = 0;start<piles.size()-i;start++) {
                int end = start+i;
                dp[start][end] = max(piles[end] - dp[start][end-1],piles[start] - dp[start+1][end]);
            }
        }
        return dp[0].back() > 0;
    }
};