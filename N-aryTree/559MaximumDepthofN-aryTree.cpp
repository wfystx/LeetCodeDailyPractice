/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    int maxDepth(Node* root) {
        if(!root) return 0;
        int maxdepth = 0;
        for(auto c:root->children) maxdepth = max(maxdepth, maxDepth(c));
        return maxdepth + 1;
    }
};