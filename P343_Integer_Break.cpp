class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 1);
        for(int i = 3; i <= n; i++){
            int temp_two = 0;
            int temp_three = 0;
            int two = i - 2;
            int three = i - 3;
            if(two > 0){
                if(two == 2)      temp_two = 2 * 2;
                else if(two == 3) temp_two = 2 * 3;
                else              temp_two = dp[two] * 2;
            }
            if(three > 0){
                if(three == 3)      temp_three = 3 * 3;
                else if(three == 3) temp_three = 2 * 3;
                else                temp_three = dp[three] * 3;
            }
            dp[i] = max(temp_two, temp_three);
        }
        return dp[n];
    }
};
