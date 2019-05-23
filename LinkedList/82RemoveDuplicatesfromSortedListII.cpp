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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* cur = new ListNode(0);
        ListNode* dummy = cur;
        bool flag = true;
        while(head){
            while(head && head->next && head->val == head->next->val){
                flag = false;
                head = head->next;
            }
            if(flag){
                cur->next = head;
                cur = cur->next;
            }
            head = head->next;
            flag = true;
        }
        cur->next = NULL;
        return dummy->next;
    }
};