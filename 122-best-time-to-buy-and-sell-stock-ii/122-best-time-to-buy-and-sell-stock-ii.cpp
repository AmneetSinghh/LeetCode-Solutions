class Solution {
public:
    long dfs(int i,int buy, vector<int> &a, int n, vector<vector<int>> &dp){
        if(i==n){
            if(buy){
                return 0;
            }
            return INT_MIN;// we have to make this minimum.
        }
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

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return dfs(0,1,prices,n,dp);// 1 means you selled it previously
    }
};