/**
 Solution:
 the key point is that the last element in postorder vector is the root.
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    }
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int is, int ie, int ps, int pe){
        if(ps>pe) return NULL;
        TreeNode* temp = new TreeNode(postorder[pe]);
        int pos;
        for(int i=is; i<=ie; i++){
            if(inorder[i] == temp->val) {
                pos = i;
                break;
            }
        }
        temp->right = helper(inorder, postorder, pos+1, ie, pe-ie+pos, pe-1);
        temp->left = helper(inorder, postorder, is, pos-1, ps, pe-ie+pos-1);
        return temp;
    }
};