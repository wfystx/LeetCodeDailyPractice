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
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return {};
        return helper(1, n + 1);
    }
    vector<TreeNode*> helper(int start, int end){
        vector<TreeNode*> res;
        if(start == end) return {nullptr};
        
        for(int i = start; i < end; i++){
            vector<TreeNode*> l = helper(start, i);
            vector<TreeNode*> r = helper(i + 1, end);

            for(auto ll:l)
                for(auto rr:r){
                    TreeNode *node = new TreeNode(i);
                    node->left = ll;
                    node->right = rr;
                    res.push_back(node);
                }
        }
        
        return res;
        
    }
};