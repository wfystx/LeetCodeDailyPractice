/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> m;
        return helper(m, head);
    }
    Node* helper(unordered_map<Node*, Node*>& m, Node* head){
        if(!head) return head;
        Node* copy = new Node(head->val, NULL, NULL);
        m[head] = copy;
        copy->next = helper(m, head->next);
        copy->random = m[head->random];
        return copy;
    }
};