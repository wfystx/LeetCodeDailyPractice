/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
private:
    unordered_map<Node*,Node*> m;
public:
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        if(m.find(node) == m.end()){
            m[node] = new Node(node->val, {});
            for(auto n:node->neighbors) m[node]->neighbors.push_back(cloneGraph(n));
        }
        return m[node];
    }
};