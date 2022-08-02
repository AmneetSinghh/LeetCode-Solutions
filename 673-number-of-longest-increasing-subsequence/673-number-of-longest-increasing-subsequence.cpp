class Solution {
public:
    int findNumberOfLIS(vector<int>& a) {
        int n = a.size();
        vector<int> dp(n+12,1);
        vector<int> count(n+12,1);
        int mx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(a[j]<a[i] and dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                    count[i]=count[j];
                }
                else if(a[j]<a[i] and dp[j]+1==dp[i]){
                    count[i]+=count[j];
                }
            }
            
            mx=max(dp[i],mx);
        }
        int res=0;
        for(int i=0;i<n;i++){
            if(dp[i]==mx)res+=count[i];
        }
        return res;
    }
};