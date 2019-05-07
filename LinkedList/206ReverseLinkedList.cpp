/**
 Solution:
 We can think about do it recursively. swap every node with its next node every time and return the new head, connect them toghether.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* n = head->next;
        ListNode* newHead = reverseList(n);
        n->next = head;
        head->next = NULL;
        return newHead;
    }
};