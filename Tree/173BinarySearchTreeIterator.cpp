/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode*> stc;
public:
    BSTIterator(TreeNode* root) {
        helper(root);
    }
    void helper(TreeNode* root){
        TreeNode* cur = root;
        while(cur){
            stc.push(cur);
            cur = cur->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* cur = stc.top(); stc.pop();
        if(cur->right) helper(cur->right);
        return cur->val;   
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(stc.empty()) return false;
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */