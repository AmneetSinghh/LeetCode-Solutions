class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n = a.size();
        vector<int> vc;
        vc.push_back(a[0]);
        for(int i=1;i<n;i++){
            if(a[i]>vc.back()){
                vc.push_back(a[i]);
            }
            else{
                // find the place to override
                int l=0;
                int r=vc.size()-1;
                int res=-1;
                while(l<=r){
                    int mid = (l+r)/2;
                    if(vc[mid]>=a[i]){
                        res=mid;
                        r=mid-1;
                    }
                    else l = mid+1;
                }
                vc[res]=a[i];
            }
        }
        return vc.size();
    }
};