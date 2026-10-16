class Solution {
public:
    char maxstr(int left,int right,string& s) {
        char ans = s[left];
        for (int i = left; i < right; i++) {
            ans = max(ans, s[i]);
        }
        return ans;
    }
    char minstr(int left,int right,string& s) {
        char ans = s[left];
        for (int i = left; i < right; i++) {
            ans = min(ans, s[i]);
        }
        return ans;
    }
    bool already_sorted(string& s) {
        for(int i = 1;i<s.size();i++) {
            if(s[i]<s[i-1]) return false;
        }
        return true;
    }
    int minOperations(string s) {

        if(s.size() == 1) return 0;

        if(s.size() == 2) {
            if(s[0] <= s[1]) return 0;
            return -1;
        }

        if(already_sorted(s)) {
            return 0;
        }

        char maxelement = maxstr(0,s.size(),s);
        char minelement = minstr(0,s.size(),s);

        if(maxelement == s.back()|| minelement == s[0]) return 1;
        
        if(maxelement == s[0] && minelement == s.back()) {
            if(maxstr(1, s.size() - 1, s) != maxelement && minstr(1, s.size() - 1, s) != minelement) {
                return 3;
            }
        }
        return 2;
    }
};