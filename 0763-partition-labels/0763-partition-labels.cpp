class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> freq(26,0);
        for(char a:s) {
            freq[a-'a']++;
        }

        vector<int> ans;
        unordered_set<int> st;
        int start = 0;
        for(int end = 0;end<s.size();end++){
            freq[s[end]-'a']--;
            if(freq[s[end]-'a'] != 0) {
                st.insert(s[end]-'a');
            } 
            for(auto it = st.begin();it != st.end();) {
                if(freq[(int)*it] == 0) {
                    it = st.erase(it);
                } else {
                    ++it;
                } 
            }
            if(st.empty()) {
                ans.push_back(end-start+1);
                start = end+1;
                continue;
            }
        }
        return ans;
    }
};