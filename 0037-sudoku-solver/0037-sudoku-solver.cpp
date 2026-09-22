class Solution {
public:
    vector<vector<bool>> row;
    vector<vector<bool>> col;
    vector<vector<bool>> grid;
    vector<pair<int,int>> myarr;
    bool flag = false;
    int gridno(int i,int j) {
        return (i / 3) * 3 + (j / 3);
    }
    void backtracking(vector<vector<char>>& board,int i,int j) {
        if(flag) return;
        if(myarr.size() == 0) {
            flag = true;
            return;
        }
        int currgridno =  gridno(i,j);
        myarr.pop_back();
        for(int k = 0;k<9;k++) {
            if(row[i][k] == true || col[j][k] == true|| grid[currgridno][k] == true) continue;
            
            board[i][j] = (k+1)+'0';
            row[i][k] = true;
            col[j][k] = true;
            grid[currgridno][k] = true;

            if(myarr.size() == 0) {
                flag = true;
                return;
            }
            
            backtracking(board,myarr.back().first,myarr.back().second);

            if(flag) return; 

            board[i][j] = '.';
            row[i][k] = false;
            col[j][k] = false;
            grid[currgridno][k] = false;

        }
        
        myarr.push_back({i,j});
    }
    void solveSudoku(vector<vector<char>>& board) {
        row = vector<vector<bool>>(9,vector<bool>(9,false));
        col = vector<vector<bool>>(9,vector<bool>(9,false));
        grid = vector<vector<bool>>(9,vector<bool>(9,false));
        for(int i = 0;i<9;i++) {
            for(int j = 0;j<9;j++) {
                if(board[i][j] == '.') {
                    myarr.push_back({i,j});
                    continue;
                }
                int currno = (board[i][j] - '0')-1;
                row[i][currno] = true;
                col[j][currno] = true;
                grid[gridno(i,j)][currno] = true;
            }
        }
        if(myarr.empty()) return;
        backtracking(board,myarr.back().first,myarr.back().second);
    }
};