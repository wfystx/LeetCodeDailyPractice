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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        bool flag = false;
        while(!q.empty()){
            int sz = q.size();
            flag = false;
            for(int i = 0; i < sz; i++){
                TreeNode* tmp = q.front(); q.pop();
                if(flag == false){
                    res.push_back(tmp->val);
                    flag = true;
                } 
                if(tmp->right) q.push(tmp->right);
                if(tmp->left) q.push(tmp->left);
            }
        }
        return res;
    }
};