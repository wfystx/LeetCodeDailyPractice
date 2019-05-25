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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> temp;
        helper(root, temp, res, sum);
        return res;
    }
    void helper(TreeNode* root, vector<int> temp, vector<vector<int>>& res, int sum){
        if(!root) return;
        temp.push_back(root->val);
        if(!root->left && !root->right && root->val == sum){
            res.push_back(temp);
            return;
        }
        helper(root->left, temp, res, sum-root->val);
        helper(root->right, temp, res, sum-root->val);
    }
};