class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        set<long long> st;
        int maxstreak = 0;
        for(int x:nums) st.insert(x);
        while(!st.empty()) {
            int a = *st.begin();
            int streak = 1;
            while(st.find(1LL*a*a) != st.end()) {
                a = a*a;
                streak++;
                if(streak > maxstreak) maxstreak = streak;
                st.erase(a);
            }
            st.erase(st.begin());
        }
        if(maxstreak <= 1) return -1;
        return maxstreak;
    }
};