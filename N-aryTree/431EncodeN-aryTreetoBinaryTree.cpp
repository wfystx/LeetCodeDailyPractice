/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
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
class Codec {
public:

    // Encodes an n-ary tree to a binary tree.
    TreeNode* encode(Node* root) {
        if(!root) return nullptr;
        TreeNode* node = new TreeNode(root->val);
        if(!root->children.empty()) node->left = encode(root->children[0]);
        TreeNode* cur = node->left;
        for(int i = 1; i < root->children.size(); i++){
            cur->right = encode(root->children[i]);
            cur = cur->right;
        }
        return node;
    }

    // Decodes your binary tree to an n-ary tree.
    Node* decode(TreeNode* root) {
        if(!root) return nullptr;
        Node* node = new Node(root->val, vector<Node*>());
        TreeNode* cur = root->left;
        while(cur){
            node->children.push_back(decode(cur));
            cur = cur->right;
        }
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(root));