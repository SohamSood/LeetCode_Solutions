class Solution {
public:
    int partitionString(string s) {
        vector<int> freq(26,0);
        int start = 0;
        int count = 1;
        for(int end = 0;end<s.size();end++) {
            freq[s[end]-'a']++;
            if(freq[s[end] - 'a'] > 1) {
                for(int i = 0;i<26;i++) freq[i] = 0;
                freq[s[end]-'a'] = 1;
                start = end;
                count++;
            } 
        }
        return count;  
    }
};