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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head) return nullptr;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy, *start, *then;
        for(int i = 0; i < m - 1; i++) pre = pre->next;
        start = pre->next;
        then = start->next;
        
        for(int i = 0; i < n - m; i++){
            start->next = then->next;
            then->next = pre->next;
            pre->next = then;
            then = start->next;
        }
        return dummy->next;
    }
};