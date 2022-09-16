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
 	TreeNode* solve(vector<int> in,vector<int> post,int &index,int inorderStart,
 				int inorderEnd,int n,map<int,int> &nodeToIndex){

 		if(index<0 ||inorderStart>inorderEnd){
 			return NULL;
 		}

 		int element=post[index--];
 		TreeNode* root=new TreeNode(element);
 		int mid=nodeToIndex[element];
        root->right=solve(in,post,index,mid+1,inorderEnd,n,nodeToIndex);
 		        root->left=solve(in,post,index,inorderStart,mid-1,n,nodeToIndex);

 		return root;
 	}
 	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
 		
        int n=postorder.size();
        int postOrderIndex=n-1;
        
 		map<int,int> nodeToIndex;
 		for(int i=0;i<inorder.size();i++){
 			nodeToIndex[inorder[i]]=i;
 		}
        
 		TreeNode* ans=solve(inorder,postorder,postOrderIndex,0,n-1,n,nodeToIndex);
        
 		return ans;
 	}
};