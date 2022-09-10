class Solution {
public:
    int longestOnes(vector<int>& a, int k) {
        int n = a.size();
        int j=0;
        int mx=0;
        int flag=0;
        if(k==0)flag=1;
        for(int i=0;i<n;i++){
            if(j<i)j=i;
            while(j<n){
                if(a[j]==0){
                    if(k==0)break;
                    else --k;
                }
                ++j;
            }
            mx=max(mx,j-i);
            if(flag==0 and a[i]==0)k++;
        }
        
        
        return mx;
    }
};