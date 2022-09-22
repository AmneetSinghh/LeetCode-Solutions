class Solution {
public:
    vector<int>dx ={1,0,-1,0,1};
    int swimInWater(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size(),m=grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,0));
        visited[0][0]=1;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({grid[0][0],0,0});
        ans = grid[0][0];
        while(!pq.empty()){
            vector<int>top = pq.top();
            pq.pop();
            int x = top[1], y = top[2];
            ans = max(ans,top[0]);
            if(x==n-1&&y==m-1){
                return ans;
            }
            for(int i=0;i<4;i++){
                if(x+dx[i]>=0 && x+dx[i]<n && y+dx[i+1]>=0 && y+dx[i+1]<m && !visited[x+dx[i]][y+dx[i+1]]){
                    visited[x+dx[i]][y+dx[i+1]]=1;
                    int nextWeight = grid[x+dx[i]][y+dx[i+1]];
                    pq.push({nextWeight,x+dx[i],y+dx[i+1]}); 
                }
            }
        }
        return -1;
    }
};