class Solution {
public:
    string decodeAtIndex(string s, int k) {
        string ans = "";
        map<int,long long> freq;
        long long size = 0;
        for(int i = 0;i<s.size();i++) {
            if(s[i] >= 'a' && s[i] <= 'z') size++;
            else {
                size = size * (s[i]-'0');
            }
            freq[i] = size;
        } 
        for(int i = s.size() - 1; i >= 0; i--) {
            if (s[i] >= '2' && s[i] <= '9') {

                int no = s[i] - '0';
                size /= no;
                k %= size;

                if (k == 0) k = size;
            } 
            else {
                if (k == size) {
                    return string(1, s[i]);
                }
                size--;
            }
        }
        return "";
    }
};