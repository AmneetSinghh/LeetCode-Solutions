class Solution {
public:
    int dfs(int i,int mask,int n,vector<int>& a, vector<int>& b,vector< vector<int>> &dp){
        if(i>=n)return 0;
        if(dp[i][mask]!=-1){
            return dp[i][mask];
        }
        int profit = INT_MAX;
        for(int j=0;j<n;j++){
            if(mask&(1<<j)){
                // this means this value in Bth array is available
                profit = min(profit, (a[i]^b[j])+dfs(i+1,mask^(1<<j),n,a,b,dp));
            }
        }
        return dp[i][mask]=profit;
    }
    
    int minimumXORSum(vector<int>& a, vector<int>& b) {
        int n = a.size();
        vector< vector<int>> dp(n,vector<int>(1<<n,-1));
        return dfs(0,(1<<n)-1,n,a,b,dp);
    }
};