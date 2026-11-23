class Solution {
public:
    int getmask(string& s) {
        int no = 0;
        for(char c:s) {
            no = no | (1<<(c-'a'));
        }
        return no;
    }
    int maxProduct(vector<string>& words) {
        int ans = 0;
        vector<int> myarr;
        for(string s:words) myarr.push_back(getmask(s));
        for(int i = 0;i<words.size();i++) {
            for(int j = i+1;j<words.size();j++){ 
                if((myarr[i]&myarr[j]) == 0) {
                    ans = max(ans,(int)words[i].size() * (int)words[j].size());
                }
            }
        }
        return ans;
    }
};