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
private:
    double res = DBL_MAX;
    int r;
public:
    int closestValue(TreeNode* root, double target) {
        r = root->val;
        helper(root, target);
        return r;
    }
    void helper(TreeNode* root, double target){
        if(!root) return;
        double tmp = abs(root->val - target);
        if(tmp < res){
            res = tmp;
            r = root->val;
        } 
        if(root->val < target) helper(root->right, target);
        else helper(root->left, target);
    }
};