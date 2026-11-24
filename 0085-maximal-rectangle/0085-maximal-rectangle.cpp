class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {

        vector<vector<int>> dp_row = vector<vector<int>>(matrix.size(),vector<int>(matrix[0].size(),0));

        for(int j = 0;j<matrix[0].size();j++) {
            if(matrix.back()[j] == '1') {
                dp_row.back()[j] = 1;
            }
        }
    
        for(int i = matrix.size()-2;i>=0;i--) {
            for(int j = 0;j<matrix[0].size();j++) {
                if(matrix[i][j] == '1') {
                    dp_row[i][j] = dp_row[i+1][j]+1;
                } 
            }
        }

        vector<vector<int>> dp_col = vector<vector<int>>(matrix.size(),vector<int>(matrix[0].size(),0));

        for(int i = 0;i<matrix.size();i++) {
            if(matrix[i].back() == '1') {
                dp_col[i].back() = 1;
            } 
        }

        for(int i = 0;i<matrix.size();i++) {
            for(int j = matrix[0].size()-2;j>=0;j--) {
                if(matrix[i][j] == '1') {
                    dp_col[i][j] = dp_col[i][j+1]+1;
                }
            }
        }
        
        int maxans = 0;
        for(int i = 0;i<matrix.size();i++) {
            for(int j = 0;j<matrix[0].size();j++) {
                if(matrix[i][j] == 0) continue;
                int row_min = dp_row[i][j];
                int col_max = dp_col[i][j];
                
                for(int newj = j;newj<col_max+j;newj++) {
                    row_min = min(row_min,dp_row[i][newj]);
                    maxans = max(maxans,row_min*(newj-j+1));
                }

                // cout<<"{"<<row_min<<","<<col_max<<","<<maxans<<"} "; 
            }
            // cout<<endl;
        }

        // cout<<"demoooo"<<endl;


        // for(int i = 0;i<matrix.size();i++) {
        //     for(int j = 0;j<matrix[0].size();j++) {
        //         cout<<dp_row[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<"next one"<<endl;
        // for(int i = 0;i<matrix.size();i++) {
        //     for(int j = 0;j<matrix[0].size();j++) {
        //         cout<<dp_col[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return maxans;
    }
};