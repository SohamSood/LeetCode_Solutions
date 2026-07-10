class Solution {
public:
    int counta = 0;
    int countb = 0;
    int countc = 0;
    int ans = 0;
    

    bool check() {
        if(counta != 0 && countb != 0 && countc != 0) return true;
        return false;
    }
    int numberOfSubstrings(string s) {
        int start = 0;
        for(int end = 0;end<s.size();end++) {
            if(s[end] == 'a') counta++;
            if(s[end] == 'b') countb++;
            if(s[end] == 'c') countc++;
            while(check() && start<=end) {
                ans+=s.size()-end;
                if(s[start] == 'a') counta--;
                else if(s[start] == 'b') countb--;
                else if(s[start] == 'c') countc--;
                start++;
            }
        }
        return ans;
    }
};