class Solution {
public:
    
    vector<int> pathsWithMaxScore(vector<string>& board) {
        vector<vector<pair<int,int>>> dp(board.size(),vector<pair<int,int>>(board[0].size(),{0,0}));
        dp[board.size()-1][board[0].size()-1] = {0,1};
        int MOD = 1e9+7;
        for(int i = board.size()-1;i>=0;i--) {
            for(int j = board[0].size()-1;j>=0;j--) {
                if(board[i][j] == 'X' ) continue;
                if(i == board.size()-1 && j == board[0].size() - 1) continue;
                int maxval = -1;
                int freq = 0;
                if(i+1<board.size() && j+1<board.size() && board[i+1][j+1] != 'X') {
                    //ower left diagonal;
                    if(dp[i+1][j+1].first > maxval) {
                        maxval = dp[i+1][j+1].first;
                        freq = dp[i+1][j+1].second;
                    } else if(dp[i+1][j+1].first == maxval){
                        freq= (freq+dp[i+1][j+1].second)%MOD;
                    }
                }
                if(i+1<board.size() && board[i+1][j] != 'X') {
                    //bottom
                    if(dp[i+1][j].first > maxval) {
                        maxval = dp[i+1][j].first;
                        freq = dp[i+1][j].second;
                    }  else if(dp[i+1][j].first == maxval){
                        freq= (freq+dp[i+1][j].second)%MOD;
                    }
                }
                if(j+1 < board[0].size() && board[i][j+1] != 'X'){
                    //right
                    if(dp[i][j+1].first > maxval) {
                        maxval = dp[i][j+1].first;
                        freq = dp[i][j+1].second;
                    } else if(dp[i][j+1].first == maxval){
                        freq= (freq+dp[i][j+1].second)%MOD;
                    }
                }
                if(board[i][j] == 'E') {
                    if(freq == 0) return {0,0};
                    return {(maxval)%MOD,freq};
                }
                if(freq!=0) {
                    dp[i][j] = { (maxval+(board[i][j]-'0'))%MOD ,freq};
                }
            }
        } 
        // for(int i = 0;i<board.size();i++) {
        //     for(int j = 0;j<board[0].size();j++) {
        //         cout<<"{"<<dp[i][j].first<<","<<dp[i][j].second<<"} ";
        //     }
        //     cout<<endl;
        // }
        return {dp[0][0].first,dp[0][0].second};   
    }
};