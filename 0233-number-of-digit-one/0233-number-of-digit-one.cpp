class Solution {
public:
    vector<vector<vector<int>>> dp;
    int dfs(string& s,int pos,bool tight,int ones) {
        if(pos == s.size()) {
            dp[pos][tight][ones] = ones;
            return ones;
        }
        if(dp[pos][tight][ones] != -1) return dp[pos][tight][ones];
        int ans = 0;
        if(tight == true) {
            for(int i = 0;i<=s[pos]-'0';i++) {
                if(i == s[pos]-'0')  ans+=dfs(s,pos+1,true,ones+(i==1));
                else ans+=dfs(s,pos+1,false,ones+(i==1));                
            }
        } else {
            for(int i = 0;i<=9;i++) {
                ans+=dfs(s,pos+1,false,ones+(i == 1));
            }
        }
        dp[pos][tight][ones] = ans;
        return ans;
    }
    int countDigitOne(int n) {
        dp.assign(11, vector<vector<int>>(2, vector<int>(11, -1)));
        string s = to_string(n);
        return dfs(s,0,true,0);
    }
};