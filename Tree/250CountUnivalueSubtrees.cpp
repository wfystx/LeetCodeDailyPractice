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
    int countUnivalSubtrees(TreeNode* root) {
        int cnt = 0;
        helper(root, cnt);
        return cnt;
    }
    bool helper(TreeNode* root, int& cnt){
        if(!root) return true;
        bool left = helper(root->left, cnt);
        bool right = helper(root->right, cnt);
        
        if(left && right && (!root->left || root->left->val == root->val) && (!root->right || root->right->val == root->val)){
            cnt++;
            return true;
        }
        return false;
    }
};