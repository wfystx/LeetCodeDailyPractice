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
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> m;
        return dfs(root, m, k);
    }
    
    bool dfs(TreeNode* root, unordered_set<int>& m, int k){
        if(!root) return false;
        if(m.count(k - root->val)) return true;
        m.insert(root->val);
        return dfs(root->left, m, k) || dfs(root->right, m, k);
    }
};