/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node* node = new Node(insertVal, NULL);
        if(!head){
            node->next = node;
            return node;
        }
        Node* cur = head->next, *pre = head;
        while(cur != head){
            if((cur->val >= insertVal && insertVal >= pre->val) || (cur->val < pre->val && (insertVal < cur->val || pre->val < insertVal))){
                node->next = cur;
                pre->next = node;
                return head;
            }
            pre = pre->next;
            cur = cur->next;
        }
        node->next = cur;
        pre->next = node;
        return head;
    }
};