/* 
    Time: O(n^2)
    Space: O(n^2)
    Tag: DSU, Matrix, Graph
    Difficulty: M
*/

class Solution {

    vector<int> parent;
    vector<int> rank;

    int find_(int node){
    if(node==parent[node]){
        return node;
    }
    return parent[node]=find_(parent[node]);
}
    
void union_(int a,int b){
    a = find_(a);
    b = find_(b);
    if(a==b)return;
    if(rank[a]<rank[b]){
        parent[a]=b;
        rank[b]+=rank[a];
    }
    else if(rank[b]<rank[a]){
        parent[b]=a;
        rank[a]+=rank[b];
    }
    else{
        parent[a]=b;
        rank[b]+=rank[a];
    }
}

public:
    int largestIsland(vector<vector<int>> &grid) {
        int n = grid.size();
        parent.resize(n * n, -1);
        rank.resize(n * n, 0);
        for(int i=0;i<n*n;i++)parent[i]=i,rank[i]=1;

        vector<pair<int, int>> moves = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    for (auto move : moves) {
                        if (i + move.first >= 0 && j + move.second >= 0 && i + move.first < n && j + move.second < n && grid[i + move.first][j + move.second]) {
                            union_(i * n + j, (i + move.first) * n + (j + move.second));
                        }
                    }
                }
            }
        }

        int res = *max_element(rank.begin(), rank.end());

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    int curRes = 0;
                    unordered_set<int> st;
                    for (auto move : moves) {
                        if (i + move.first >= 0 && j + move.second >= 0 && i + move.first < n && j + move.second < n && grid[i + move.first][j + move.second]) {
                            int comp = find_((i + move.first) * n + (j + move.second));
                            if (st.find(comp) == st.end()) {// we have to get uniquee components, so that we can check whether its already added to our sum or not.
                                curRes += rank[comp];
                                st.insert(comp);
                            }
                        }
                        res = max(res, 1 + curRes);
                    }
                }
            }
        }
        return res;
    }
};