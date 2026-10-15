class Solution {
public: 
    int maxans = 0;
    int setBits(int no) {
        int count = 0;
        for(int i = 0;i<32;i++) {
            if((no& (1<<i)) != 0) count++;
        }
        return count;
    }
    int isValid(int no,string& b) {
        for(char c:b) {
            if((no&(1<<(c-'a'))) == 0) {
                no = no | (1<<(c-'a'));
            } else {
                return -1;
            }
        }
        return no;
    }
    void backtracking(vector<string>& arr,int idx,int no) {
        maxans = max(maxans,setBits(no));
        for(;idx<arr.size();idx++){
            int ans = isValid(no,arr[idx]);
            if(ans != -1) {
                backtracking(arr,idx+1,ans);
            }
        }
    }
    int setState(string& a) {
        int no = 0;
        for(char c:a) {
            no = no | (1<<(c-'a'));
        }
        return no;
    }
    int maxLength(vector<string>& arr) {
        backtracking(arr,0,0);
        return maxans;
    }
};