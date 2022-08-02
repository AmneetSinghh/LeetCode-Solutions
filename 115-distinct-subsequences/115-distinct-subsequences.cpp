class Solution {
public:
    
    int dfs(int i,int j, string s, string t, vector< vector<int>> &dp){
        if(j==0)return 1;
        if(i==0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i-1]==t[j-1]){
            return dp[i][j]=dfs(i-1,j-1,s,t,dp)+dfs(i-1,j,s,t,dp);
        }
        return dp[i][j]=dfs(i-1,j,s,t,dp);
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
//         // vector< vector<int>> dp(n+1,vector<int>(m+1,-1));
//         // return dfs(n,m,s,t,dp);
//         vector< vector<long>> dp(n+1,vector<long>(m+1,0));
//         for(int i=0;i<=n;i++)dp[i][0]=1;// j ==0 means, when all t th string is empty
        
//         for(int i=1;i<=n;i++){
//             for(int j=1;j<=m;j++){
//                 if(s[i-1]==t[j-1]){
//                      dp[i][j]=(int)(dp[i-1][j-1]+dp[i-1][j]);
//                 }
//                 else{
//                     dp[i][j]=dp[i-1][j];
//                 } 
//             }
//         }
        
//         return (int)dp[n][m];
        
        
        
//**********************  space optimation  ******************************
        vector<long> prev(m+1,0),cur(m+1,0);
        prev[0]=cur[0]=1;        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                     cur[j]=(int)(prev[j-1]+prev[j]);
                }
                else{
                    cur[j]=prev[j];
                } 
            }
            prev=cur;
        }
        return prev[m];
        
        
    }
};