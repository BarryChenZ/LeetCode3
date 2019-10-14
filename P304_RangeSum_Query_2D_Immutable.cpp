class NumMatrix {
public:
    int **dp;
    NumMatrix(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return;
        
        dp = new int*[matrix.size() + 1];
        for(int i = 0; i <= matrix.size(); i++) dp[i] = new int[matrix[0].size() + 1];
        for(int r = 0; r <= matrix.size(); r++){
            for(int c = 0; c <= matrix[0].size(); c++){
                dp[r][c] = 0;
            }
        }
        
        for(int r = 0; r < matrix.size(); r++){
            for(int c = 0; c < matrix[0].size(); c++){
                dp[r + 1][c + 1] = dp[r + 1][c] + dp[r][c + 1] + matrix[r][c] - dp[r][c];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2 + 1][col2 + 1] - dp[row1][col2 + 1] - dp[row2 + 1][col1] + dp[row1][col1];
    }
};
