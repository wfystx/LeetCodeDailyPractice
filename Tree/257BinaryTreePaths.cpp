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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(!root) return res;
        helper(root, res, to_string(root->val));
        return res;
    }
    void helper(TreeNode* root, vector<string>& res, string temp){
        if(!root->left && !root->right) {
            res.push_back(temp);
            return;
        }
        if(root->left) helper(root->left, res, temp + "->" + to_string(root->left->val));
        if(root->right) helper(root->right, res, temp + "->" + to_string(root->right->val));
    }
};