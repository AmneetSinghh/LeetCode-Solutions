class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        // binary search;
        int n=a.size();
        int l=0;
        int r=n-1;
        int mid;
        if(n==1)return a[0];
        while(l<=r){
            mid=(l+r)/2;
            if(mid==0){
                if(a[mid+1]!=a[mid])return a[mid];
            }
            else if(mid==n-1){
                if(a[mid-1]!=a[mid])return a[mid];
            }
            else if(a[mid]!=a[mid-1] && a[mid]!=a[mid+1])return a[mid];
            
            
            if(mid%2==0){
                if(a[mid+1]==a[mid])l=mid+1;
                else r=mid-1;
            }
            else{
                if(a[mid-1]==a[mid])l=mid+1;
                else r=mid-1;
            }
        }
        return a[l];
    }
};