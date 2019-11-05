class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.empty()) return {};
        vector<int> ans;
        sort(nums.begin(), nums.end());
        
        vector<int> dp(nums.size(), 1);
        vector<int> forward(nums.size(), 0);
        
        int max_len = 0;
        int start_point = nums.size() - 1;
        for(int i = nums.size() - 1; i >= 0; i--){
            for(int j = i + 1; j < nums.size(); j++){
                if((nums[j] % nums[i]) == 0 && dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                    forward[i] = j;
                }
            }
            if(dp[i] > max_len){
                max_len = dp[i];
                start_point = i;
            }
        }
        int cur = start_point;
        for(int i = 0; i < max_len; i++){
            ans.push_back(nums[cur]);
            cur = forward[cur];
        }
        return ans;
    }
};
