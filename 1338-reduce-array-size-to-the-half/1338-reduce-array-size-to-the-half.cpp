class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> freq;
        for(int x:arr) freq[x]++;
        vector<int> myarr;
        for(auto& p: freq) myarr.push_back(p.second);
        sort(myarr.begin(),myarr.end(),greater<int>());
        int currentremoval = 0;
        for(int i = 0;i<myarr.size();i++) {
            currentremoval += myarr[i];
            if(currentremoval >= arr.size() / 2) return i+1;
        }
        return 1;
    }
};