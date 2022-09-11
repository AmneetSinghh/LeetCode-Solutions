class Solution {
public:
    int jump(vector<int>& a) {
        if(a.size()==1)return 0;
        int j=a[0],i=1,jump=1,n=a.size();
        while(i<=a.size()-2 and j<=a.size()-2){
            int prev = i;
            int next = j;
            while(i<=j){
                next = max(i+a[i],next);
                ++i;
            }
            ++jump;
            i=j;
            j=next;
            if(j>=a.size()-1)break;
        }
        
        
        return jump;
    }
};