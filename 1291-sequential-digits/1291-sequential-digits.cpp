class Solution {
public:
    vector<int> myarr;
    void generate(int no,int lastno) {
        if(lastno == 9) return;
        no = no*10 + lastno+1;
        myarr.push_back(no);
        generate(no,lastno+1);
        no = no/10;
    }
    vector<int> sequentialDigits(int low, int high) {
        for(int i = 1;i<=9;i++) {
            myarr.push_back(i);
            generate(i,i);
        }
        sort(myarr.begin(),myarr.end());
        auto lb = lower_bound(myarr.begin(), myarr.end(), low);
        auto ub = upper_bound(myarr.begin(), myarr.end(), high);
        vector<int> ans;
        for (auto it = lb; it != ub; it++) {
            ans.push_back(*it);
        }
        return ans;
    }
};