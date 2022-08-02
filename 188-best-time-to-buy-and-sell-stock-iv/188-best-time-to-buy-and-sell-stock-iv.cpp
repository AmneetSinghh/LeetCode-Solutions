class Solution {
public:
    int maxProfit(int k, vector<int>& a) {
        // we will solve this problem with transactions number 1 means buy and 0 means sell.
        int n = a.size();
        vector< vector<int>> dp(n+1,vector<int>(2*k+12,0));
        
        for(int i=n-1;i>=0;i--){
            for(int j=2*k-1;j>=0;j--){
                if(j%2==0) dp[i][j]=max(-a[i]+dp[i+1][j+1],dp[i+1][j]);
                else{
                    dp[i][j]=max(a[i]+dp[i+1][j+1],dp[i+1][j]);
                }
            }
        }
        return dp[0][0];
    }
};