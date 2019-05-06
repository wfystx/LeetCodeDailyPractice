/**
 Solution:
 DFS
*/
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
    unordered_map<Node*, Node*> map;
public:
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        if(map.find(node) == map.end()){
            vector<Node*> vec;
            map[node] = new Node(node->val, vec);
            for(auto v:node->neighbors){
                map[node]->neighbors.push_back(cloneGraph(v));
            }
        }
        return map[node];
    }
};