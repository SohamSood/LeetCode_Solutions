class Solution {
public:
   
    bool check2(int u,int x,vector<vector<int>>& preferences,vector<int>& myarr) {
        int preferenceofu = myarr[u];
        for(int i = 0;i<preferences[u].size();i++) {
            if(preferences[u][i] == preferenceofu) return false;
            if(preferences[u][i] == x) return true;
        }
        return false;
    }
    bool check(int x,int y,vector<vector<int>>& preferences,vector<int>& myarr) {
        for(int i = 0;i<preferences[x].size();i++) {
            if(preferences[x][i] != y) {
                if(check2(preferences[x][i],x,preferences,myarr)) return true;
            } else return false;
        }
        return false;
    } 
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        int count = 0;
        vector<int> myarr(n);
        for(int i = 0;i<pairs.size();i++) {
            myarr[pairs[i][0]] = pairs[i][1];
            myarr[pairs[i][1]] = pairs[i][0];
        }
        for(int i = 0;i<pairs.size();i++) {
            if(check(pairs[i][0],pairs[i][1],preferences,myarr)){
                count++;
            } 
            if(check(pairs[i][1],pairs[i][0],preferences,myarr)){
                count++;
            }
        }
        return count;
    }
};