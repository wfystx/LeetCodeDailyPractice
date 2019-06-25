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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,vector<TreeNode*>> m;
        vector<TreeNode*> res;
        helper(root, m);
        for(auto item:m) if(item.second.size() > 1) res.push_back(item.second[0]);
        return res;
    }
    string helper(TreeNode* root, unordered_map<string,vector<TreeNode*>>& m){
        if(!root) return "";
        string s = "(" + helper(root->left, m) + to_string(root->val) + helper(root->right, m) + ")";
        m[s].push_back(root);
        return s;
    }
};