/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
        struct ListNode *ptr1, *ptr2;
        struct ListNode *prev1, *prev2;
        int t;

        ptr1 = head;
        prev1 = NULL;
        while(NULL != ptr1 && ptr1->val < x) {
                prev1= ptr1;
                ptr1 = ptr1->next;
        }

        if(NULL == ptr1)
                return head;

        prev2 = ptr1;
        ptr2 = ptr1->next;
        while(NULL != ptr2) {
                if(ptr2->val < x) {
                        prev2->next = ptr2->next;
                        ptr2->next = ptr1;

                        //prev1 might be NULL
                        if(NULL == prev1)
                                head = ptr2;
                        else
                                prev1->next = ptr2;

                        prev1 = ptr2;
                        ptr2 = prev2->next;
                } else {
                        prev2 = ptr2;
                        ptr2 = ptr2->next;
                }
        }
        return head;
}
