/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st; 
        TreeNode* node = root;
        vector<int> inorder; 
        while(true) {
            while(node) {
                 st.push(node);
                 inorder.push_back(node->val);
                node = node->left;
               
            }
            if(st.empty())break;
            node = st.top(); 
            st.pop(); 
            node = node->right;
        }  
        return inorder;
    }
};