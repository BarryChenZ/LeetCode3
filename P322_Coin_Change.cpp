class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        //sort(coins.begin(), coins.end());
        dp[0] = 0;
        for(int i = 1; i <= amount; i++){
            //bool find = false;
            for(int j = coins.size() - 1; j >= 0; j--){
                if(i - coins[j] >= 0){
                    
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
    
                }
            }
            //if(find == false) dp[i] = -1;
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};
