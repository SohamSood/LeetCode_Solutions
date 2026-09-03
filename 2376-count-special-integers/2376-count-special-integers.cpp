//2376 
class Solution {
public:
    vector<vector<vector<vector<int>>>> dp = vector<vector<vector<vector<int>>>>(
        10,
        vector<vector<vector<int>>>(
            1024,
            vector<vector<int>>(2, vector<int>(11, -1))
        )
    );
    string no;
    int backtracking(string& currno,int mask,bool tight,int len) {
        int count = 0;
        if(currno.size() == len) return 1; //reached the max
        if(dp[currno.size()][mask][tight][len] != -1) return dp[currno.size()][mask][tight][len]; //this state was previously visited
        if(tight == true) {
            int limit = no[currno.size()] - '0';
            for(int i = 0;i<=limit;i++) {
                if(currno.size() == 0 && i == 0) continue; //handle leading zeroes
                if (mask & (1 << i)) continue; //that value has already been used
                currno.push_back(i + '0'); //backtracking add that digit

                bool newTight = (i == no[currno.size() - 1] - '0');

                count += backtracking(currno,mask | (1 << i),newTight,len);
                currno.pop_back(); //removing that digit
            }
        } else {
            for(int i = 0;i<=9;i++) {
                if (mask & (1 << i)) continue; //that value has already been used

                if(currno.size() == 0 && i == 0) continue; //hnadling leading zeroes
                currno.push_back(i + '0');  //backtracking add that digit
                count+=backtracking(currno, mask | (1 << i),false,len);
                currno.pop_back(); //removing that digit
            }

        }
        dp[currno.size()][mask][tight][len]  = count;
        return count;
    }

    int countSpecialNumbers(int n) {
        no = to_string(n);
        int size = no.size();
        string currno = "";
        int ans = 0;

        for(int len = 1; len <= no.size(); len++) {
            bool tight = (len == no.size());
            ans += backtracking(currno, 0, tight, len);
        }

        return ans;
    }
};