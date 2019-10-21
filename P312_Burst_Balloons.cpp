class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size()));
        for(int i = 1; i < nums.size() - 1; i++){//區間長度
            for(int j = 1; j + i - 1< nums.size() - 1; j++){
                int s = 0;
                for(int k = j; k <= j + i - 1; k++){
                    s = max(s, nums[j-1]*nums[k]*nums[j+i] + dp[j][k-1] + dp[k+1][j+i-1]);
                }
                dp[j][j+i-1] = s;
            }
        }
        return dp[1][nums.size() - 2];
    }
};
