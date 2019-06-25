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
    vector<int> preorder(Node* root) {
        stack<Node*> s;
        vector<int> res;
        if(!root) return res;
        s.push(root);
        while(!s.empty()){
            Node* tmp = s.top(); s.pop();
            res.push_back(tmp->val);
            reverse(tmp->children.begin(), tmp->children.end());
            for(auto c:tmp->children) s.push(c);
        }
        return res;
    }
};