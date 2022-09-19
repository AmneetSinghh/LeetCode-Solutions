# define pi pair<long,long>
class Solution {
public:
    long long mod=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        
        vector<vector<vector<int>>> adj(n);
        for(auto x:roads){
            adj[x[0]].push_back({x[1],x[2]});
            adj[x[1]].push_back({x[0],x[2]});
        }
        
        vector<long long> dp(n);
        vector<long long> dist(n,LLONG_MAX);
        dist[0]=0;
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        dp[0]=1;
        pq.push({0,0});
        while(!pq.empty()){
            pi temp = pq.top();
            pq.pop();
            // if(dist[temp.second]<temp.first) continue;
            for(auto x:adj[temp.second]){
                if(dist[x[0]]==(long long)x[1]+temp.first){
                    dp[x[0]] = (dp[x[0]]+dp[temp.second])%mod;
                }
                else if(dist[x[0]]>(long long)x[1]+(long long)temp.first){
                    dist[x[0]]=(long long)x[1]+(long long)temp.first;
                    pq.push({dist[x[0]],x[0]});
                    dp[x[0]] = dp[temp.second];
                }
            }
        }
        
        return dp[n-1]%mod;
    }
};