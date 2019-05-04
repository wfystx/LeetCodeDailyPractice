/**
 Solution:
 Merge sort
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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* dummy;
        while(fast && fast->next){
            dummy = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        dummy->next = NULL;
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);
        return merge(l1,l2);
    }
    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* rev = new ListNode(0);
        ListNode* temp = rev;
        while(l1 && l2){
            if(l1->val>l2->val){
                rev->next = l2;
                l2 = l2->next;
            }else{
                rev->next = l1;
                l1 = l1->next;
            }
            rev = rev->next;
        }
        if(l1) rev->next = l1;
        else if(l2) rev->next = l2;
        return temp->next;
    }
};