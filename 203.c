/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
        struct ListNode *curr = head;
        struct ListNode *prev = NULL;

        while(NULL != curr) {
                if(curr->val == val) {
                        if(prev != NULL)
                                prev->next = curr->next;
                        else
                                head = curr->next;
                } else {
                        prev = curr;
                }
                curr = curr->next;

        }

        return head;

}
