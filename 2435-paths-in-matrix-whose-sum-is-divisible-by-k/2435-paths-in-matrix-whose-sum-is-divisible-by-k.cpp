class Solution {
public:
    
    int m = 1e9+7;
    int K=0;// sum here is < K
    int helper(vector<vector<int>>&grid, int i, int j, int sum, vector<vector<vector<int>>> &dp){
        if(i >= grid.size() || j >=grid[0].size()) return 0;
        if(i==grid.size()-1&&j==grid[0].size()-1){
           if((sum+ grid[i][j])%K!=0) return 0;
            else return 1;
        }
        if(dp[i][j][sum]!=-1) return dp[i][j][sum];
        return dp[i][j][sum] = (helper(grid,i+1,j,(sum + grid[i][j])%K,dp)%m + helper(grid,i,j+1,(sum + grid[i][j])%K,dp)%m)%m;
    }
    
    
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        K=k;
        vector<vector<vector<int>>> dp(grid.size()+1 , vector<vector<int>>(grid[0].size()+1 , vector<int> (k , - 1)));
        return helper(grid,0,0,0,dp);
    }
};