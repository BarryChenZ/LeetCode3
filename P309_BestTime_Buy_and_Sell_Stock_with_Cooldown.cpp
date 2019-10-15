class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int s0 = 0;
        int s1 = INT_MIN;
        int s2 = 0;
        
        for(int i = 0; i < prices.size(); i++){
            int tmp = s0;
            s0 = max(s0, s1 + prices[i]);
            s1 = max(s1, s2 - prices[i]);
            s2 = max(s2, tmp);
        }
        return max(s0, s2);
    }
};
