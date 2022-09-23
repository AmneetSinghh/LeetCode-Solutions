class Solution {
public:
    vector<vector<int>> res;
    void dfs(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, int &timer, vector<int> adj[]) {
    vis[node] = 1;
    tin[node] = low[node] = timer++;
    for(auto child: adj[node]) {
        if(child == parent) continue;
        if(!vis[child]) {
            dfs(child, node, vis, tin, low, timer, adj);
            low[node] = min(low[node], low[child]);
            if(tin[node]<low[child]) {
               res.push_back({node,child});
            }
        } else {
            low[node] = min(low[node], tin[child]);
        }
    }
}
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& c) {
        vector<int> adj[n];
        res.clear();
        int m = c.size();
        for(int i = 0;i<m;i++) {
            int u  = c[i][0];
            int v = c[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> tin(n, -1);
        vector<int> low(n, -1);
        vector<int> vis(n, 0);
        int timer = 0;
        for(int i = 0;i<n;i++) {
            if(!vis[i]) {
                dfs(i, -1, vis, tin, low, timer, adj);
            }
        }
        return res;
    }
};