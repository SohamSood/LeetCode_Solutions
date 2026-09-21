class Solution {
public:
    int divide(int dvd, int dvr) {
        bool flag = ((dvd > 0 && dvr < 0) || (dvd < 0 && dvr > 0));
        if(dvd == dvr) return 1; 

        long long dividend = abs((long long)dvd);
        long long divisor = abs((long long)dvr);
        long long ans = 0;
        
        while(dividend >= divisor) {
            // find the no which is just lower that that power dividend * 2 ^ x
            int pow = 0;
            while(dividend >= (divisor<<(pow+1))) {
                pow++;
            }
            ans += (1LL<<pow);
            dividend = dividend - (divisor<<pow);
        }
        if(flag) ans  = -ans;
        if (ans > INT_MAX) return INT_MAX;
        
        return ans;
    }
};