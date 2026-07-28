class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0') return 0;

        vector<int> dp(s.size(),0);
        dp[0] = 1;
        for(int i = 1;i<s.size();i++) {
            if (s[i] == '0' && s[i-1] != '1' && s[i-1] != '2') return 0;
            if (s[i] == '0' && (s[i-1] == '1' || s[i-1] == '2')) {
                if(i > 1) {
                    dp[i] += dp[i-2];
                } else {
                    dp[i]++;
                }
            } else if (((s[i-1]-'0')*10 + (s[i]-'0')) >= 10 && ((s[i-1]-'0')*10 + (s[i]-'0')) <= 26) {
                if(i > 1) {
                    dp[i] += dp[i-2];
                } else {
                    dp[i]++;
                }
                dp[i] += dp[i-1];
            } else {
                dp[i] = dp[i-1];
            }
        }
        return dp[dp.size()-1];
    }
};