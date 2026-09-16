class Solution {
public:
    bool canRun(int n,long long time,vector<int>& batteries) {
        long long req_time = 0;
        for(int i = 0;i<batteries.size();i++){
            req_time += min<long long>(batteries[i],time);
            if((time * 1LL * n) <= req_time) return true;
        } 
        return false;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum = 0;
        for(int x: batteries) sum+=x;
        long long left = 0;
        long long right = sum / n;
        long long ans = 0;
        while(left <= right) {
            long long mid = left+(right-left)/2;
            if(canRun(n,mid,batteries)) {
                left = mid+1;
                ans = mid;
            } else  {
                right = mid-1;
            }
        }
        return ans;
    }
};