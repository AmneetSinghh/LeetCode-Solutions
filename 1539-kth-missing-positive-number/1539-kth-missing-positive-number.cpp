class Solution {
public:
    int findKthPositive(vector<int>& a, int k) {
        int l=0;
        int r = a.size()-1;
        int ans = -1;
        while(l<=r){
            int mid = (l+r)/2;
            if(a[mid]-(mid+1)>=k){
                ans = mid;
                r=mid-1;
            }
            else l = mid+1;
        }
        
        if(ans==-1){
            int prev  = a[a.size()-1]-(a.size());
            return a[a.size()-1]+(k-prev);
        }
        if(ans-1>=0){
            int prev  = a[ans-1]-(ans);
            return a[ans-1]+(k-prev);
        }
        return k;
    }
};