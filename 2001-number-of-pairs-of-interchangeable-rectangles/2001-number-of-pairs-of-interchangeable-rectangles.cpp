class Solution {
public:
    int gcd(int a,int b) {
        if(a == 0) return b;
        return gcd(b%a,a);
    }
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        map<pair<int,int>,int> freq;
        long long ans = 0;
        for(int i = 0;i<rectangles.size();i++) {
            int current_gcd = gcd(rectangles[i][0],rectangles[i][1]);
            freq[{rectangles[i][0]/current_gcd,rectangles[i][1]/current_gcd}]++;
        }
        for(auto& p:freq) {
            if(p.second <= 1) continue;
            ans +=((1LL * p.second)*((1LL*p.second) - 1)) /2;
        }
        return ans;
    }
};