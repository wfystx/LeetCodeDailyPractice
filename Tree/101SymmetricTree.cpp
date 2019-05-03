/**
 Solution:
 Use recursion in a helper function. Access every left and right node.
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
    bool isSymmetric(TreeNode* root) {
        return check(root, root);        
    }
    bool check(TreeNode* l, TreeNode* r){
        if(!l && !r) return true;
        if(!l) return false;
        if(!r) return false;
        if(l->val != r->val) return false;
        else return check(l->left, r->right) && check(l->right, r->left);
        return true;
    }
};