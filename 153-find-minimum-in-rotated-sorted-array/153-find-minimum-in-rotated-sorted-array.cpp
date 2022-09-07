class Solution {
public:
    int findMin(vector<int>& a) {
        int l =0;
        int r = a.size()-1;
        if(a.size()==1)return a[0];
        int ans=0;
        while(l<=r){
            int mid = (l+r)/2;
            if(mid-1>=0 and mid+1<a.size() and  a[mid-1]>a[mid] and a[mid]<a[mid+1])return a[mid];
            if(mid-1<0 and a[mid]<a[mid+1])return a[mid];
            if(mid+1>=a.size() and a[mid-1]>a[mid])return a[mid];
            if(a[mid]>a[r])l=mid+1;
            else ans = a[mid],r=mid-1;
        }
        return ans;
    }
};
// we have to find the peak element.