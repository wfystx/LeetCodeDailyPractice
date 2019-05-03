/**
 Solution:
 the key point is that the first element in preorder vector is the root.
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie){
        if(is>ie || ps>pe) return NULL;
        TreeNode* temp = new TreeNode(preorder[ps]);
        int pos;
        for(int i=is; i<=ie; i++){
            if(inorder[i]==temp->val){
                pos = i;
                break;
            }
        }
        temp->left = helper(preorder, inorder, ps+1, ps+pos-is,is,pos-1);
        temp->right = helper(preorder, inorder, pe-ie+pos+1, pe, pos+1, ie);
        return temp;
    }
};