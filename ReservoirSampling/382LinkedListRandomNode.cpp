/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* node;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        node = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        ListNode* temp = node;
        ListNode* res;
        int cnt = 0;
        while(temp){
            cnt++;
            if(rand() % cnt == 0) res = temp;
            temp = temp->next;
        }
        return res->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */