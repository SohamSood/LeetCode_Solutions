class Solution {
public:
    bool isPalindrome(int x) {
        string a = to_string(x);
        string b = a;
        reverse(a.begin(),a.end());
        if(b == a) return true;
        return false;
    }
};