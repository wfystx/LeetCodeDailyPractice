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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            vector<int> v;
            for(int i = 0; i < sz; i++){
                Node* tmp = q.front(); q.pop();
                v.push_back(tmp->val);
                if(!tmp->children.empty()) for(auto c:tmp->children) q.push(c);
            }
            res.push_back(v);
        }
        return res;
    }
};