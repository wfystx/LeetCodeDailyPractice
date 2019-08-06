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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            vector<int> level;
            for(int i = 0; i < sz; i++){
                TreeNode* tmp = q.front(); q.pop();
                level.push_back(tmp->val);
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
            }
            res.push_back(level);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};