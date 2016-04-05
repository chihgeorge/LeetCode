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
    
    bool valid(TreeNode *p, long low, long high){
        if(p == NULL) return true;
        
        return  (low == NULL || p->val > low) && (p->val < high || high == NULL) 
                && valid(p->left, low, p->val) 
                && valid(p->right, p->val, high);
    }
};