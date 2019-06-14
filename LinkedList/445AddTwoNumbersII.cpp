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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        while(l1){
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2){
            s2.push(l2->val);
            l2 = l2->next;
        }
        int sum = 0;
        ListNode* node = new ListNode(0);
        while(!s1.empty() || !s2.empty()){
            if(!s1.empty()){ sum += s1.top(); s1.pop();}
            if(!s2.empty()){ sum += s2.top(); s2.pop();}
            node->val = sum % 10;
            ListNode* head = new ListNode(sum / 10);
            head->next = node;
            node = head;
            sum /= 10;
        }
        return node->val == 0 ? node->next : node;
    }
};