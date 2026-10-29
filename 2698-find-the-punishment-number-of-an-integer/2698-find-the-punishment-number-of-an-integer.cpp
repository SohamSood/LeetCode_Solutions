class Solution {
public:
    bool flag;
    string str;
    int target;
    void backtracking(int sum,int no,int i) {
        if(flag) return;
        if(i == str.size()) {
            if(sum + no == target) {
                flag = true;
            }
            return;
        }
        backtracking(sum+no*10+(str[i]-'0'),0,i+1);
        backtracking(sum,no*10+(str[i]-'0'),i+1);
    }
    int punishmentNumber(int n) {
        int count = 0;
        for(int i = 0;i<=n;i++) {
            flag = false;
            target = i;
            str = to_string(i*i);
            backtracking(0,0,0);
            if(flag) count+=(i*i);
        }
        return count;
    }
};