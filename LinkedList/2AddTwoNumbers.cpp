/**
 Solution:
 Use recursion to pass every node of l1 and l2. If the sum is equal or greater than 10, pass 1 and rev->next to function again.
 Base case: (!l1 && !l2), (!l1), (!l2).
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2) return NULL;
        if(!l1) return l2;
        if(!l2) return l1;
        int sum = l1->val + l2->val;
        ListNode *rev = new ListNode(sum%10);
        rev->next = addTwoNumbers(l1->next, l2->next);
        if(sum>=10) rev->next = addTwoNumbers(rev->next, new ListNode(1));
        return rev;
    }
};