class Solution {
public:
    vector<vector<vector<vector<int>>>>dp;
    string currno;
    int backtracking(int length,int mask,bool tight,bool started) {
        if(length == 0) return 1;
        if(dp[length][mask][tight][started] != -1) return dp[length][mask][tight][started];
        int ans = 0;
        int limit = 9;
        if(tight) {
            limit = currno[currno.size() - length] - '0';
            if((mask & (1<<limit)) == 0) {
                int newMask = mask | (1<<limit);
                if(started == 0 && limit == 0)  {
                    ans += backtracking(length - 1, mask, true, false);
                    
                } else {
                    ans += backtracking(length-1,newMask,true,true);
                }
            }
        } else limit = 10;

        for(int i = 0;i<limit;i++) {

            if((mask & (1<<i)) != 0) continue;
            int newMask = mask | (1<<i);

            if(started == 0 && i == 0)  {
                ans += backtracking(length - 1, mask, false, false);
                continue;
            } 
            ans += backtracking(length-1,newMask,false,true);
        }
        dp[length][mask][tight][started] = ans;
        return ans;

    }
    int numDupDigitsAtMostN(int n) {
        currno = to_string(n);
        dp = vector<vector<vector<vector<int>>>>(currno.size()+1,(vector<vector<vector<int>>>(1024,vector<vector<int>>(2,vector<int>(2,-1)))));
        // dp state is [lenght][mask][tight][start]
        int ans = backtracking(currno.size(),0,true,false);
        return n+1-ans;
    }
};