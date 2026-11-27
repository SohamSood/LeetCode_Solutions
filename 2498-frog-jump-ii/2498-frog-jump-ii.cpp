class Solution {
public:
    int maxJump(vector<int>& stones) {
        if(stones.size() == 2) return stones[1]-stones[0];
        int ans = stones[2]-stones[0];
        for(int i = 2;i<stones.size();i++){
            ans = max(ans,stones[i]-stones[i-2]);
        }
        return ans;
    }
};