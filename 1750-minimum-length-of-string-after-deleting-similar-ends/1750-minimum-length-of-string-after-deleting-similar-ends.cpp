class Solution {
public:
    int minimumLength(string s) {
        int left = 0;
        int right = s.size()-1;
        while(left<right){
            if(right < 0 || left >= s.size()) break;
            if(s[left]!=s[right]) break;
            while(left < right && s[left] == s[left+1]) left++;
            while(left < right && s[right] == s[right-1]) right--;
            left++;
            right--;
            if(left>right) return 0;
            cout<<s[left]<< " " <<s[right]<<endl;
        }
        cout<<right<<" "<<left<<endl;
        return right-left+1;
    }
};