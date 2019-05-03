/**
 In-order Traversal
 In-order traversal is to traverse the left subtree first. Then visit the root. Finally, traverse the right subtree.
 
 Solution:
 Create a vector to store each node accessed. Use a helper function to traverse nodes recursively. Return NULL when current node is NULL.
 Step 1: Go to left node of current node.
 Step 2: When there is no more left node, store the current node's value.
 Step 3: Go to right node of current node.
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> rev;
        helper(root, rev);
        return rev;
    }
    void helper(TreeNode* root, vector<int> &rev){
        if(root==NULL) return;
        else{
            
            helper(root->left, rev);
            rev.push_back(root->val);
            helper(root->right, rev);
        }
    }
};
