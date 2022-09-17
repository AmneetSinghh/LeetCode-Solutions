class Solution {
public:
    int ladderLength(string a, string b, vector<string>& words) {
        queue<pair<string,int> > q;
        q.push({a,1});
        int flag=0;
        // Faster than my previous solution;
        set<string> s(words.begin(),words.end());
        while(!q.empty())
        {
            string cur=q.front().first;
            int dis=q.front().second;
            q.pop();
            if(cur==b){flag=dis;break;}
            // try eery possible words;
            for(int i=0;i<cur.size();i++)
            {
                char save=cur[i];
                for(char v='a';v<='z';v++){
                    cur[i]=v;
                    if(s.find(cur)!=s.end()){
                        s.erase(cur);
                        q.push({cur,dis+1});
                    }
                }
                cur[i]=save;
                
            }

        }
        return flag;
        
    }
};