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
    bool isValidBST(TreeNode* root) {
        return valid(root, NULL, NULL);
    }
    
    bool valid(TreeNode *p, TreeNode *low, TreeNode *high){
        if(p == NULL) return true;
        
        return  (low == NULL || p->val >= low->val) && (p->val <= high->val || high == NULL) 
                && valid(p->left, low, p) 
                && valid(p->right, p, high);
    }
};