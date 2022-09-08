class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int x,y,max=INT_MIN;
        vector<bool> prev(n,true);
        for(int i=n-1; i>=0; i--){
            vector<bool> cur (n,false);
             for(int j=i; j<=n-1; j++){
                  if(i==j)
                       cur[j] = true;
                  else if(s[i] == s[j]){
                     if(j-i == 1) cur[j]=true;
                      else
                        cur[j] = prev[j-1];
                    }
                  if(cur[j] && j-i>=max){
                       max=j-i;
                        x=i;
                        y=j;
                    }
                }
            prev = cur;
            }
    

        return s.substr(x,y-x+1);
    }
};