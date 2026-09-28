class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int,int> freq;
        int maxans = 0;
        for(int x:nums) freq[x] += x;
        int previous1 = 0;
        int previouskey = -1;
        int previous2 = 0;
    
        for(auto p:freq) {
            int currmax;
            if(abs(previouskey - p.first) == 1) {
                currmax = max(p.second+previous2 , previous1);
            } else {
                currmax = previous1 + p.second;
            }
            previouskey = p.first;
            previous2 = previous1;
            previous1 = currmax;
        } 

        return previous1;
    }
};