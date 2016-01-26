/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
        struct ListNode *curr1, *curr2, *master, *pre;
        uint8_t sign;

        curr1 = l1;
        curr2 = l2;
        while(curr1 && curr2) {
                curr1 = curr1->next;
                curr2 = curr2->next;
        }
        master = curr1 ? l1 : l2;

        curr2 = curr1 ? l2 : l1;
        pre = curr1 = master;
        sign = 0;
        while(curr2) {
                curr1->val += sign;
                sign = 0;
                if((curr1->val += curr2->val) >= 10) {
                        curr1->val -= 10;
                        sign = 1;
                }

                pre = curr1;
                curr1 = curr1->next;
                curr2 = curr2->next;
        }

        while(sign) {
                if(!curr1)
                        curr1 = pre->next = calloc(sizeof(struct ListNode), 1);

                if((curr1->val += sign) >= 10) {
                        curr1->val -= 10;
                        sign = 1;
                } else {
                        sign = 0;
                }

                pre = curr1;
                curr1 = curr1->next;
        }

        return master;
}
