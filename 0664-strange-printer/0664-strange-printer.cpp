class Solution {
public:
    int strangePrinter(string ss) {
        string s = "";
        if(!ss.empty()) s.push_back(ss[0]);
        for(int i = 1;i<ss.size();i++) {
            if(ss[i] != ss[i-1]) s.push_back(ss[i]);
        }
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),(int)s.size()+1));
        for(int i = 0;i<s.size();i++) dp[i][i] = 1;
        for(int i = 2;i<=s.size();i++) {
            for(int j = 0;j<=s.size()-i;j++) {
                int start = j;
                int end = i+j-1;
                for(int k = start; k < end; k++) {
                    if(s[k] == s[end]) {
                        int cost = dp[start][k];
                        if(k+1 <= end-1) cost += dp[k+1][end-1];
                        dp[start][end] = min(dp[start][end], cost);
                    }
                }
                for(int k = end; k > start; k--) {
                    if(s[k] == s[start]) {
                        int cost = dp[k][end];
                        if(start+1 <= k-1) cost += dp[start+1][k-1];
                        dp[start][end] = min(dp[start][end], cost);
                    }
                }
                dp[start][end] = min({dp[start][end],dp[start+1][end]+1,dp[start][end-1]+1});
            }
        }
        return dp[0].back();
    }
};