class Solution {
public:
    long long gcd(int a,int b) {
        if(b == 0) return a;
        return gcd(b,a%b);
    }
    long long calculate(long long curr,int a,int b,int c) {
        long long ab = (a / gcd(a, b)) * b;
        long long bc = (b / gcd(b, c)) * c;
        long long ac = (a / gcd(a, c)) * c;

        long long abc = (ab / gcd(ab, c)) * c;

        long long ans = curr/a + curr/b + curr/c;
        ans = ans - curr/ab  - curr/bc - curr/ac + curr/abc;

        return ans;
    }
    int nthUglyNumber(int n, int a, int b, int c) {
        long long left = 0;
        long long right = 2e9;
        while(left<right) {
            int mid = left+(right-left)/2;
            int count = calculate(mid,a,b,c);
            if (count >= n) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};