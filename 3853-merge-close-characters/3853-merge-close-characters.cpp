class Solution {
public:
    string mergeCharacters(string s, int k) {
        vector<int> latest(26,-1);
        string ans = "";
        for(int i = 0;i<s.size();i++) {
            int current = s[i] - 'a';
            if(latest[current] != -1 && abs(latest[current] - (int)ans.size()) <= k) {
                continue;   
            }
            latest[current] = ans.size();
            ans.push_back(s[i]);
        }
        return ans;
    }
};