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
        return valid(root, LONG_MIN, LONG_MAX);
    }
    
    bool valid(TreeNode *p, long low, long high){
        if(p == NULL) return true;
        
        return  p->val > low && p->val < high 
                && valid(p->left, low, p->val) 
                && valid(p->right, p->val, high);
    }
};