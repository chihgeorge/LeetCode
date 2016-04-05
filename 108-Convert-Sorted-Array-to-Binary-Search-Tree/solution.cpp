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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sorted(nums, 0, nums.size() - 1);
    }
    
    TreeNode* sorted(vector<int>& nums, int start, int end){
        if(start > end) return NULL;
        int mid = (start + end)/2;
        TreeNode *p = TreeNode(nums[mid]);
        p->left = sorted(nums, start, mid - 1);
        p->right = sorted(nums, mid + 1, end);
        return p;
    }
};