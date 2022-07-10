class Solution {
public:
    const int mod = 1e9 + 7; 
    void f(int s, int m, int len, vector<long long>& distinctValues) {
        if(s <= m) {
            distinctValues[len]++; 
        }
        for(int i = 2;i*s<=m;i++) {
            f(s*i,m,len+1,distinctValues);
        }
    }
    
    // we just need to get NCR. otherwise all things fine.  very easy logc.
    //As we have N = lenght of rope,, we need to find how many distinct cuts of length m we can make in it.
    long long NCR(int n, int r)
    {
    vector<int> reverse_m = {1, 500000004, 333333336, 250000002, 400000003, 166666668, 142857144, 125000001, 111111112, 700000005, 818181824, 83333334, 153846155, 71428572, 466666670, 562500004, 352941179, 55555556, 157894738, 850000006};
    if(n == r) {
        return 1; 
    }
    if(r > n) {
        return 0; 
    }
    if (r == 0) return 1;
    long long res = 1; 
    for (int k = 1; k <= r; ++k)
    {
        res *= n - k + 1;
        res %= mod; 
        res *= reverse_m[k-1];
        res %= mod; 
    }

    return res % mod;
    }
    
    
    int idealArrays(int n, int m) {
        vector<long long> distinctValues(20);
        for(int i = 2;i<=m;i++) {
            f(i,m,1,distinctValues);
        }
        long long ret = 0;
        for(int i = 1;i<20;i++) {
            if(distinctValues[i] == 0) {
                break; 
            }
            long long t = NCR(n,i);
            t *= distinctValues[i];// if we have to fill [1,2]in N =5, [1,2,3]in N =5, [1,2,3,4]in N =5, [2,4]in N =5,
            t %= mod; 
            ret += t; 
        }
        return (ret + 1) % mod; 
    }
};