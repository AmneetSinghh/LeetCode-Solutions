class BSTIterator{
    stack<TreeNode*> s;
    bool reverse = true;
    public:
    BSTIterator(TreeNode* root, bool isReverse){
        reverse= isReverse;
        pushAll(root);
    }
    void pushAll(TreeNode* root){
        while(root!=NULL){
            s.push(root);
            if(reverse == false)root=root->left;
            else root=root->right;
        }
    }
    
    int next(){
        TreeNode* top = s.top();
        s.pop();
        if(!reverse)pushAll(top->right);
        else pushAll(top->left);
        return top->val;
    }
};



class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL)return false;
        BSTIterator l(root,false);
        BSTIterator r(root,true);
        int i = l.next();
        int j = r.next();
        while(i<j){
            if(i+j == k){
                return true;
            }
            if(i+j<k)i=l.next();
            else j=r.next();
        }
        return false;
    }
};