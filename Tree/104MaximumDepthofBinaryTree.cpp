/** 
 Solution:
 Use recurrsion to solve this problem.
 Base case: root == NULL means arriving a leaf, start counting from here.
 Plus 1 at every parent node. Every paths are counted separately.
 Find the max depth of left and right paths.
 */
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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return max(maxDepth(root->left)+1, maxDepth(root->right)+1);
    }
};