class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxelement = nums[0];
        for(int x:nums) maxelement = max(maxelement,x);
        int diff = 0;
        for(int x:nums) diff+=maxelement-x;
        return diff;
    }
};