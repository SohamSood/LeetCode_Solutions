class Solution {
public:
    vector<int> freq;
    bool backtracking(string& target,int index,string& curr) {
        if(curr.size() == target.size()) return curr>target;
        for(int i = target[index]-'a';i<26;i++) {
            if(freq[i]!=0) {
                freq[i]--;
                curr.push_back(i+'a');
                if(i+'a' != target[index]) {
                    generate(curr);
                    return true;
                } else {
                    if(backtracking(target,index+1,curr)) return true;
                }
                freq[i]++;
                curr.pop_back();
            }
        }
        return false;
    }  

    void generate(string& ans) {
        for(int i = 0;i<26;i++) {
            while(freq[i] > 0) {
                freq[i]--;
                ans.push_back(i+'a');
            }
        }
    }

    string lexGreaterPermutation(string s, string target) {
        freq = vector<int>(26,0);
        for(char c:s) freq[c-'a']++;
        string ans = "";
        if(backtracking(target,0,ans)) return ans;
        return "";
    }
};