class Solution {
public:
    int numSubarraysWithSum(vector<int>& a, int goal) {
        map<int,int> mp;
        int pre=0,c=0;
        for(int i=0;i<a.size();i++){
            pre+=a[i];
            if(pre==goal)++c;
            if(mp.find(pre-goal)!=mp.end()){
                c+=(mp[pre-goal]);
            }
            mp[pre]++;
        }
        return c;
    }
};