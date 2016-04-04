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
        return valid(root, INT_MIN, INT_MAX);
    }
    
    bool valid(TreeNode *p, int min, int max){
        if(p == NULL) return true;
        
        return  p->val > min && p->val < max &&
                valid(p->left, min, p->val) && valid(p->right, p->val, max);
    }
};