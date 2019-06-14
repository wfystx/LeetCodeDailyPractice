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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<pair<int,TreeNode*>> q;
        q.push({0,root});
        map<int,vector<int>> m;
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                TreeNode *node = q.front().second;
                int tmp = q.front().first;
                q.pop();
                m[tmp].push_back(node->val);
                if(node->left) q.push({tmp - 1, node->left});
                if(node->right) q.push({tmp + 1, node->right});
            }
        }
        for(auto item:m) res.push_back(item.second);
        return res;
    }
};