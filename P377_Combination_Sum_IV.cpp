class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        if(nums.size() == 0 || target == 0) return 0;
        vector<long long> dp(target + 1, 0);
        dp[0] = 1;
        for(int i = 1; i <= target; i++){
            int count = 0;
            for(int j = 0; j < nums.size(); j++){
                if(i - nums[j] >= 0){
                    if(find(nums.begin(),nums.end(), i - nums[j]) != nums.end() || dp[i - nums[j]] > 0){
                        count += dp[i - nums[j]];
                    }
                }
            }
            dp[i] = count;
        }
        return dp[target];
    }
};
