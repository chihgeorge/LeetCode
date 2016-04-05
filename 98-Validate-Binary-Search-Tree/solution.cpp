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
    TreeNode *prep = NULL;
    bool isValidBST(TreeNode* root) {
        //return valid(root, NULL, NULL);
        return isIncreasing(root);
    }
    
    /*bool valid(TreeNode *p, TreeNode *low, TreeNode *high){
        if(p == NULL) return true;
        if(low && p->val <= low->val || high && p->val >= high->val) return false;
        return  valid(p->left, low, p) && valid(p->right, p, high);
    }*/
    
    bool isIncreasing(TreeNode *p){
        if( p == NULL)  return true;
        if(isIncreasing(p->left)){
            if(prep != NULL && prep->val > p->val)  return false;
            prep = p;
            
            return isIncreasing(p->right);
        }
        
        return false;
    }
    
};