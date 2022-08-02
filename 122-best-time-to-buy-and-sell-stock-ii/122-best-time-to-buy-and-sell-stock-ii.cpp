class Solution {
public:
    long dfs(int i,int buy, vector<int> &a, int n, vector<vector<int>> &dp){
        if(i==n)return 0;
        if(dp[i][buy]!=-1)return dp[i][buy];
        long profit=0;
        if(buy){
            profit=max(-a[i]+dfs(i+1,0,a,n,dp),0+dfs(i+1,1,a,n,dp));// buy or not buy
        }
        else{
            profit=max(a[i]+dfs(i+1,1,a,n,dp),0+dfs(i+1,0,a,n,dp));// sell or not sell
        }
        return dp[i][buy]=profit;
}

    int maxProfit(vector<int>& a) {
        int n =a.size();
        // vector<vector<int>> dp(n+1,vector<int>(2,-1));
        // return dfs(0,1,prices,n,dp);// 1 means you selled it previously
                
        
        
        // memorization.
        
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        dp[n][0]=0,dp[n][1]=0;
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                long profit=0;
                if(buy){
                    profit=max(-a[i]+dp[i+1][0],dp[i+1][1]);// buy or not buy
                }
                else{
                    profit=max(a[i]+dp[i+1][1],dp[i+1][0]);// sell or not sell
                }
                dp[i][buy]=profit;
            }
        }
        
        return dp[0][1];// buy.

    }
};