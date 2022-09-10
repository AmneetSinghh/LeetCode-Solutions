class Solution {
public:
    
    int sum_of_k(vector<int>& a, int k){
        int i=0;
        int n = a.size();
        int j=0;
        int count=0;
        int sum=0;
        while(j<n){
            if(a[j]%2==1){
                ++count;
            }
            while(count>k){
                if(a[i]%2==1){
                    --count;
                }
                ++i;
            }
            sum+=(j-i+1);
            ++j;
         }
      return sum;
        
    }
    int numberOfSubarrays(vector<int>& a, int k) {
        
            int first =  sum_of_k(a,k);
            int second = sum_of_k(a,k-1);
            return first-second;
           
    }
};