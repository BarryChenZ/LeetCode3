class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int dp[n+1];
        if(n==0)
            return 1;
        dp[0]=1;
        dp[1]=10;
        int prod=9;
        n = (n>=10) ? 10 : n;
        for(int i=2;i<=n;i++)
        {
            prod = prod * (9 - i + 2);
            dp[i]=dp[i - 1] + prod;
        }
        
        return dp[n];
        
        
    }
};
