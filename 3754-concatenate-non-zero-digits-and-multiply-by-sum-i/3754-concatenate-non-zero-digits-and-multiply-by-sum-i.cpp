class Solution {
public:
    long long sumAndMultiply(int n) {
        string a = to_string(n);
        long long newno = 0;
        int sum = 0;
        for(char c:a) {
            if(c != '0') {
                sum += c-'0';
                newno = newno*10 + c-'0';
            }
        }
        return newno*sum;
    }
};