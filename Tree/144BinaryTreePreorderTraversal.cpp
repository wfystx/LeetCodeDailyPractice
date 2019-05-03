/**
 Pre-order Traversal
 Pre-order traversal is to visit the root first. Then traverse the left subtree. Finally, traverse the right subtree.
 
 Solution:
 Create a vector to store each node accessed. Use a helper function to traverse nodes recursively. Return NULL when current node is NULL.
 Step 1: Store the current node's value immediately.
 Step 2: Go to left node of current first.
 Step 3: Go to right node of current next.
 */
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> rev;
        helper(root, rev);
        return rev;
    }
    void helper(TreeNode* root, vector<int> &rev){
        if(root==NULL) return;
        else{
            rev.push_back(root->val);
            helper(root->left, rev);
            helper(root->right, rev);
        }
    }
};
