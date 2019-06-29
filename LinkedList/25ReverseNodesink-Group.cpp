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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k == 1) return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *pre = dummy, *cur = head, *nxt;
        int num = 0;
        while(cur){
            cur = cur->next;
            num++;
        }
        while(num >= k){
            cur = pre->next;
            nxt = cur->next;
            for(int i = 1; i < k; i++){
                cur->next = nxt->next;
                nxt->next = pre->next;
                pre->next = nxt;
                nxt = cur->next;
            }
            pre = cur;
            num -= k;
        }
        return dummy->next;
    }
};