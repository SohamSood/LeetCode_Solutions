class Solution {
public:
    char ans(char no,int shift) {
        return 'a' + (((no-'a')+shift) % 26);
    }
    string shiftingLetters(string s, vector<int>& shifts) {
        int count = 0;
        for(int i = shifts.size()-1;i>=0;i--) {
            count= (count + shifts[i]) % 26;
            s[i] = ans(s[i],count);
        }
        return s;
    }
};