class Solution {
public:
     unordered_map<string,int> emailGroup;
    int find_parent(int node,vector<int> &Parent){
    if(node==Parent[node]){
        return node;
    }
    return Parent[node]=find_parent(Parent[node],Parent);
}

    
void Union(int a,int b,vector<int> &Parent, vector<int> &Rank,vector<vector<string>>& A){
    a = find_parent(a,Parent);
    b = find_parent(b,Parent);
    if(a==b){
        return;
    }
    if(Rank[a]<Rank[b]){
        Parent[a]=b;
    }
    else if(Rank[b]<Rank[a]){
        Parent[b]=a;
    }
    else{
        Parent[a]=b;
        Rank[b]++;
    }
}
    vector<vector<string>> accountsMerge(vector<vector<string>>& a) {
        int n = a.size();
        emailGroup.clear();
        vector<int> Parent(n,0);
        vector<int> Rank(n,0);
        for(int i=0;i<n;i++)Parent[i]=i;
        for(int i=0;i<n;i++){
            for(int j=1;j<a[i].size();j++){
                string email = a[i][j];
                if(emailGroup.find(email)==emailGroup.end()){
                    emailGroup[email]= i;
                }
                else{
                    Union(i,emailGroup[email],Parent,Rank,a);   // childrens match
                
                }
            }
        }
        
        unordered_map<int, vector<string>> components;
        for (auto emailIterator : emailGroup) {
            string email = emailIterator.first;
            int group = emailIterator.second;
            components[find_parent(group,Parent)].push_back(email);
        }

        // Sort the components and add the account name
        vector<vector<string>> mergedAccounts;
        for (auto componentIterator : components) {
            int group = componentIterator.first;
            vector<string> component = {a[group][0]};
            component.insert(component.end(), componentIterator.second.begin(), 
                          componentIterator.second.end());
            sort(component.begin() + 1, component.end());
            mergedAccounts.push_back(component);
        }
        
        return mergedAccounts;
        
    }
};