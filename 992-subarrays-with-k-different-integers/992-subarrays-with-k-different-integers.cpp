class Solution {
public:
    int subarray_sum(vector<int>& a, int k){
        int i=0;
        int j=0;
        int n = a.size();
        unordered_map<int,int> store;
        int count=0;
        while(j<n){
            store[a[j]]++;
            while(store.size()>k){
                store[a[i]]--;
                if(store[a[i]]==0)store.erase(a[i]);
                ++i;
            }
            count+=(j-i+1);
            ++j;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& a, int k) {
        int first = subarray_sum(a,k);
        int second = subarray_sum(a,k-1);
        return first-second;
    }
};