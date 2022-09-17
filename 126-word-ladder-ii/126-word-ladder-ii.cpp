class Solution {
    bool check(string& a,string& b) {
        int count=0;
        for (int i=0; count < 2 && i<a.size(); i++) 
            count += a[i] != b[i];
        return count == 1;
    }
    void dfs(unordered_map<string,vector<string>> &mp,vector<string>& path,int idx,string& beginWord,vector<vector<string>>& result) {
        if (path[idx] == beginWord) {
            result.push_back({});
            for (int i=idx; i>=0; i--)
                result.back().push_back(path[i]);
        } 
        else 
            for (auto word : mp[path[idx]]) {
                path[idx+1] = word;
                dfs(mp,path,idx+1,beginWord,result);
            }   
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& words) {
        unordered_map<string,int> seen;
        for (auto word : words) { seen[word] = INT_MAX; }
        
        if (seen.find(endWord) == seen.end()) return {};
        if (seen.find(beginWord) == seen.end()) words.push_back(beginWord);
        
        unordered_map<string,vector<string>> links;
        
        for (int i=0; i<words.size(); i++)
            for (int j=i+1; j<words.size(); j++)
                if (check(words[i],words[j])) {
                    links[words[i]].push_back(words[j]);
                    links[words[j]].push_back(words[i]);
                }
        
        queue<string> qu;
        qu.push(beginWord);
        seen[beginWord] = 0;
        int level=0, done=0;
        
        unordered_map<string,vector<string>> bfs;
        
        while (qu.size() && ! done) {
            level += 1;
            int size = qu.size();
            while (size--) {
                auto word = qu.front(); qu.pop();
                if (word == endWord) {
                    done = 1;
                    break;
                }
                for (auto link : links[word]) {
                    if (seen[link] < level) 
                        continue;
                    if (seen[link] > level) {
                        seen[link] = level;
                        qu.push(link);
                    }
                    bfs[link].push_back(word);
                }
            }
        }                            
        vector<vector<string>> result;
        vector<string> path(500);
        path[0] = endWord;
        
        dfs(bfs,path,0,beginWord,result);
        
        return result;
    }
};