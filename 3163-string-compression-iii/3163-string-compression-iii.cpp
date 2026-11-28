class Solution {
public:
    string ans = "";
    int streak(string& word,int idx) {
        int i = idx;
        for(;i<word.size();i++)  {
            if(word[i] != word[idx]) break;
        }
        // cout<<idx<<" "<<i<<endl;
        int count = i - idx;
        if(count >= 9) {
            int a = count/9;
            for(int i = 0;i<a;i++) {
                ans.push_back('9');
                ans.push_back(word[idx]);
            }
        }
        count = count%9;
        if(count!=0) {
            ans.push_back(count+'0');
            ans.push_back(word[idx]);
        }
        return i-1;
    }
    string compressedString(string word) {
        for(int i = 0;i<word.size();i++) {
            cout<<i<<"  ";
            i = streak(word,i);    
        }
        return ans;
    }
};