class Solution {
public:
    vector<int> word1;
    int lastoccurence(int val) {
        int left = 0;
        int right = word1.size();
        while(left<right) {
            int mid = left+(right-left) / 2;
            if(word1[mid] <= val) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return word1.size()-left;
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {

        vector<int> freq(26,0);
        vector<int> ans;
        unordered_map<int,int> mp;
        
        for(string x:words)  {
            for(char word:x) {
                freq[word-'a']++;
            }
            for(int i = 0;i<freq.size();i++) {
                if(freq[i] != 0) {
                    word1.push_back(freq[i]);
                    break;
                }
            }
            for(int i = 0;i<26;i++) freq[i] = 0;
        }
        sort(word1.begin(),word1.end());
        for(string x:queries)  {
            for(char word:x) {
                freq[word-'a']++;
            }
            for(int i = 0;i<freq.size();i++) {
                if(freq[i] != 0) {
                    if(mp.find(freq[i]) == mp.end()) {
                        mp[freq[i]]  = lastoccurence(freq[i]);
                    }
                    ans.push_back(mp[freq[i]]);
                    break;
                }
            }
            for(int i = 0;i<26;i++) freq[i] = 0;
        }
        for(int x:word1) cout<<x<<endl;
        return ans;
    }
};