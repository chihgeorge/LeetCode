/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return maxDepth(root) != -1;
    }
    
    int maxDepth(TreeNode *root){
        if(!root)   return 0;
        int L = maxDepth(root->left);
        if(L == -1) return -1;
        int R = maxDepth(root->right);
        if(R == -1) return -1;
        
        return (abs(L - R) > 1) ? -1 : max(L,R) + 1;
    }
};