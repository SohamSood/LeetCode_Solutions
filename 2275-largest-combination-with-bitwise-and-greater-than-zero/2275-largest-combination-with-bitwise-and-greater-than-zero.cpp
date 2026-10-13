class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> myarr(32,0);
        int ans = 0;
        for(int x:candidates) {
            for(int i = 0;i<32;i++) {
                if((x&(1<<i)) != 0) {
                    myarr[i]++;
                    ans = max(ans,myarr[i]);
                } 
            }
        }
        return ans;
    }
};