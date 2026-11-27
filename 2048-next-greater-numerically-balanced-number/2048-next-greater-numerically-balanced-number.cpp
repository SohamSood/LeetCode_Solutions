class Solution {
public:
    vector<int> freq;
    string ans;
    bool ansfound = false;
    int curr;
    bool valid() {
        if(ans.empty()) return false;
        for(int i = 1;i<=9;i++) {
            if(freq[i] != 0 && freq[i]!=i) return false;
        }
        return stoi(ans) > curr;
    }
    void backtracking(string& no,bool lead,int idx) {
        if(ansfound) return;
        if(idx == no.size()) {
            if(valid()) ansfound = true;
            return;
        }
        int i = 1;
        if(lead == true) i = no[idx]-'0';
        for(;i<=9;i++) {
            if(freq[i] < i) {
                freq[i]++;
                ans.push_back(i+'0');
                if(lead && i ==  no[idx]-'0') backtracking(no,true,idx+1);
                else backtracking(no,false,idx+1);
                if (ansfound) return; 
                ans.pop_back();
                freq[i]--;
            }
        }
    }
    void search(int len) {
        if(ansfound) return;
        if(len == ans.size()) {
            if(valid()) ansfound = true;
            return;
        }
        for(int i = 1;i<=9;i++) {
            if(freq[i] < i) {
                freq[i]++;
                ans.push_back(i+'0');
                search(len);
                if (ansfound) return; 
                ans.pop_back();
                freq[i]--;
            }
        }
    }
    int nextBeautifulNumber(int n) {
        freq = vector<int>(10,0);
        curr = n;
        ans = "";
        string s = to_string(n);
        backtracking(s,true,0);
        if(!ansfound) {
            search(s.size()+1);
        }
        return stoi(ans);
    }
};