class Solution {
public:
    vector<vector<int>> dp;
    int row, col;
    int maxval;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(!matrix.size() || !matrix[0].size()) return 0;
        
        row = matrix.size();
        col = matrix[0].size();
        maxval = INT_MIN;
        
        dp.resize(row, vector<int>(col, -1));
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(dp[i][j] == -1){
                    dp[i][j] = dfs(matrix, i, j, INT_MIN);    
                }
            }
        }
        return maxval;
    }
    int dfs(vector<vector<int>>& matrix, int i, int j, int number){
        if(i < 0|| j < 0|| j >= col|| i >= row || matrix[i][j] == INT_MAX - 1) return 0;
        
        if(number >= matrix[i][j]) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int cur = matrix[i][j];
        matrix[i][j] = INT_MAX - 1;
        
        int left   = dfs(matrix, i, j - 1, cur);
        int right  = dfs(matrix, i, j + 1, cur);
        int top    = dfs(matrix, i - 1, j, cur);
        int bottom = dfs(matrix, i + 1, j, cur);
        matrix[i][j] = cur;
        
        dp[i][j] = max({left,right,top,bottom}) + 1;
        maxval = max(maxval, dp[i][j]);
        return dp[i][j];
    }
};
