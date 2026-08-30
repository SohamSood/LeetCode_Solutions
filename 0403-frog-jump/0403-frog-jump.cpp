class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int,int> freq;
        for(int i = 0;i<stones.size();i++) {
            freq[stones[i]] = i;
        }
        vector<unordered_set<int>> dp(stones.size());
        dp[0].insert(0);
        for(int i = 0;i<stones.size();i++) {
            for(int nextstep:dp[i]) {
                if(nextstep != 0 && freq.find(nextstep+stones[i]) != freq.end()) { //like is this a valid jump
                    dp[freq[nextstep+stones[i]]].insert(nextstep);
                }
                if(nextstep-1 >=1 && freq.find(nextstep-1+stones[i]) != freq.end()) {
                    dp[freq[nextstep+stones[i]-1]].insert(nextstep-1);
                }
                if(freq.find(nextstep+1+stones[i]) != freq.end()) {
                    dp[freq[nextstep+stones[i]+1]].insert(nextstep+1);
                }
            }
        }
        for(int i = 0;i<dp.size();i++) {
            cout<<i<<"-"<<stones[i]<<" -> ";
            for(int x:dp[i]) cout<<x<<" ";
            cout<<endl<<endl;
        }
        return dp.back().size() != 0;
    }
};