/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* prev;
    Node* treeToDoublyList(Node* root) {
        if(!root) return nullptr;
        Node* dummy = new Node(0, NULL, NULL);
        prev = dummy;
        helper(root);
        prev->right = dummy->right;
        dummy->right->left = prev;
        return dummy->right;
    }
    void helper(Node* root){
        if(!root) return;
        helper(root->left);
        prev->right = root;
        root->left = prev;
        prev = root;
        helper(root->right);
    }
};