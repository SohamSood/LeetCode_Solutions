class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        vector<vector<int>> dp(arr.size(),vector<int>(arr.size(),2));
        unordered_map<int,int> freq;
        for(int i = 0;i<arr.size();i++) {
            freq[arr[i]] = i;
        }

        int maxvalue = 0;
        for(int i = 0;i<arr.size();i++) {
            for(int j = 0;j<i;j++) {
                int diff = arr[i]-arr[j];
                if(freq.find(diff) != freq.end() && freq[diff] < j) {
                    dp[j][i] = dp[freq[diff]][j]+1;
                    maxvalue = max(maxvalue,dp[j][i]);
                } 
            }
        }
        return maxvalue;
    }
};