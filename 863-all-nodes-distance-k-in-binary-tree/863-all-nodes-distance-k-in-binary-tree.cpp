/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<int> res;
void subtree(TreeNode* root, int depth){
        if(!root or depth < 0)return;
        if(depth==0){
            res.push_back(root->val);
            return;
        }
        subtree(root->left,depth-1);
        subtree(root->right,depth-1);
        
    }

int dfs(TreeNode* root, TreeNode * target, int depth){
    
    if(!root){
        return INT_MAX;
    }
    
    if(root==target){
        subtree(root,depth);
        return depth-1;
    }
    int left = dfs(root->left,target,depth);
    if(left!=INT_MAX){// no need to check in right.
        if(left==0){
            res.push_back(root->val);
            return INT_MAX;
        }
        subtree(root->right,left-1);
        return left-1;
    }
    
    int right = dfs(root->right,target,depth);
    if(right!=INT_MAX){
        if(right==0){
             res.push_back(root->val);
            return INT_MAX;
        }
        subtree(root->left,right-1);
        return right-1;
    }
    return INT_MAX;
}
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        res.clear();
        dfs(root,target,k);
        return res;
    }
    
    
};