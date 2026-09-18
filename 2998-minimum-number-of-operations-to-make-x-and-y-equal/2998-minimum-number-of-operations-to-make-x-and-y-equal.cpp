class Solution {
public:
    bool inlimit(int x,vector<bool>& visited) {
        if(x>=0  && x<=1e4 && visited[x] == false) {
            visited[x] = true;
            return true;
        }
        return false;
    }
    int minimumOperationsToMakeEqual(int x, int y) {
        vector<bool> visited(1e4+1,false);
        visited[x] = true;
        queue<int> q;
        q.push(x);
        int level = 0;
        while(!q.empty()) {
            int size = q.size();
            for(int k= 0;k<size;k++) {
                int curr = q.front();
                q.pop();
                if(curr  == y) return level;
                if(inlimit(curr-1,visited)) {
                    q.push(curr-1);
                }
                if(inlimit(curr+1,visited)) {
                    q.push(curr+1);
                }
                if(curr%11 == 0 && inlimit(curr/11,visited)) {
                    q.push(curr/11);
                }
                if(curr%5 == 0 && inlimit(curr/5,visited)) {
                    q.push(curr/5);
                }
            }
            level++;
        }
        return -1;
    }
};