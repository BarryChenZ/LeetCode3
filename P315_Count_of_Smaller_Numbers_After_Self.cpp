class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        deque<int> sorted;
        vector<int> ans(nums.size(), 0);
        
        for(int i = nums.size()-1; i >= 0; i--){
            auto it = lower_bound(sorted.begin(), sorted.end(), nums[i]);
            ans[i] = distance(sorted.begin(), it);
            sorted.insert(it, nums[i]);
        }
        return ans;
    }
};
