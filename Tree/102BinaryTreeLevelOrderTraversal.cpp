/**
 Solution:
 Create a 2-dimension vector to store levels. 
 Create a vector of int to store nodes in each level.
 Create a queue of int to store nodes in each level.
 Step 1: Check base case. If root == NULL, return the empty vector;
 Step 2: Push the root and NULL to the queue to start the loop.
 Step 3: Use a while loop to pop out front node in the queue as cur.
    case 1: If the current node is NULL which means this level is done.
            Push temp vector to result vector and clear temp vector.
            If there is no more element in queue, the while loop should end,
            if there are elements in it, push a NULL to queue which means the 
            end of next level.
    case 2: If the current node is not NULL, push this node to temp vector.
            Also, find the left and right node of it to store in the queue 
            in order.
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> rev;
        if(!root) return rev;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> temp;
        while(!q.empty()){
            TreeNode *cur = q.front();
            q.pop();
            if(cur==NULL){
                rev.push_back(temp);
                temp.resize(0);
                if(!q.empty()) q.push(NULL);
            }else{
                temp.push_back(cur->val);
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
        }
        return rev;
    }
};