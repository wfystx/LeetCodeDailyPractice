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
    ListNode* partition(ListNode* head, int x) {
        ListNode *front = new ListNode(0), *tail = new ListNode(0), *l1 = front, *l2 = tail;
        while(head){
            if(head->val >= x){
                l2->next = head;
                l2 = l2->next;
            }else {
                l1->next = head;
                l1 = l1->next;
            }
            head = head->next;
        }
        l2->next = nullptr;
        l1->next = tail->next;
        return front->next;
    }
};