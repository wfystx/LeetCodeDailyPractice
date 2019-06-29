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
    ListNode* find(ListNode* head){
        if(!head->next->next) return head;
        return find(head->next);
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0) return head;
        int cnt = 0;
        ListNode* cur = head;
        while(cur){
            cur = cur->next;
            cnt++;
        }
        k %= cnt;
        
        while(k-- > 0){
            ListNode* newTail = find(head), *newHead = newTail->next;
            newHead->next = head;
            newTail->next = nullptr;
            head = newHead;
        }
        return head;
    }
};