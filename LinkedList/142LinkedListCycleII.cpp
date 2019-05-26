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
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return NULL;
        bool cycle = false;
        ListNode *l1 = head, *l2 = head;
        while(l1 && l2 && l2->next){
            l1 = l1->next; l2 = l2->next->next;
            if(l1 == l2){
                cycle = true;
                break;
            }
        } 
        if(!cycle) return NULL;
        l1 = head;
        while(l1 != l2){
            l1 = l1->next; l2 = l2->next;
        }
        return l1;
    }
};