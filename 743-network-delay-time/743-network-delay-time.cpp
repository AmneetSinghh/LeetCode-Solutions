class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>>graph[n+1];
        
        for(int i=0; i<times.size(); i++){
            graph[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        
        vector<int>dist(n+1, INT_MAX);
        dist[k] = 0;
        
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>>pq;
        
        pq.push({0, k});
        
        while(!pq.empty()){
            int w = pq.top().first;
            int v = pq.top().second;
            
            pq.pop();
            
            for(auto it: graph[v]){
               if(dist[v]+it.second < dist[it.first]){
                  dist[it.first] = dist[v] + it.second;
                  pq.push({dist[it.first], it.first});
               } 
            }
        }
        
        int maxAns = 0;
        for(int i=1; i<dist.size(); i++){
            maxAns = max(maxAns, dist[i]);
        }
        return maxAns == INT_MAX? -1 : maxAns;
    }
};