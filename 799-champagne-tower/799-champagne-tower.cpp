class Solution {
public:
    
    double champagneTower(int poured, int query_row, int query_glass) {
        double dp[205];
        for(int i=0;i<101;i++)dp[i]=0.0;
        dp[0]=poured*1.0;
        double res=0.0;
        for(int i=0;i<=query_row;i++){    
            double dp1[105];
            for(int j=0;j<=i+1;j++)dp1[j]=0.0;
                for(int j=0;j<=i;j++){
                    if( i == query_row && j== query_glass){
                    if(dp[j]-1>0){
                        res=1.0;
                        break;
                     }
                     else res=dp[j];
                    }
                if(dp[j]-1>0){
                    dp[j]--;
                    dp1[j]+=(dp[j]/(double)2.0);
                    dp1[j+1]+=(dp[j]/(double)2.0);
                }
            }
            
            for(int j=0;j<=i+1;j++)dp[j]=dp1[j];            

        }
        return res;
    }
};