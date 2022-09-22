class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> dist(n, vector<int> (m, INT_MAX));
        pq.push({0, {0, 0}});
        dist[0][0] = 0;
        vector<int> delrow = {1, 0, -1, 0};
        vector<int> delcol = {0, 1, 0, -1};
        while(!pq.empty()) {
            int diff = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            if(row == n - 1 and col == m - 1) return diff;
            for(int i=0;i<4;i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow >= 0 and ncol >= 0 and nrow < n and ncol < m) {
                    int ndiff = max(diff, abs(heights[nrow][ncol] - heights[row][col]));
                    if(dist[nrow][ncol] > ndiff) {
                        dist[nrow][ncol] = ndiff;
                        pq.push({dist[nrow][ncol], {nrow, ncol}});
                    }
                }
            }
        }
        return -1;
    }
};