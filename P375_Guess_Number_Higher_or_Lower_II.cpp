class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        return solve_dp(dp, 1, n);
    }
    int solve_dp(vector<vector<int>>& dp, int l, int r){
        if(l >= r) return 0;
        if(dp[l][r]) return dp[l][r];
        int res = INT_MAX;
        for(int i = l; i <= r; i++){
            res = min(res, i + max(solve_dp(dp, l, i - 1), solve_dp(dp, i + 1, r)));
        }
        dp[l][r] = res;
        return res;
    }
};
