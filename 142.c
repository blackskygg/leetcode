/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *fast, *slow;
    
    fast = slow = head;
    do {
        if (fast && fast->next) {
            fast = fast->next->next;
        } else {
            return NULL;
        }
        
        slow = slow->next;
    } while (fast != slow);
    
    slow = head;
    while (fast != slow) {
        fast = fast->next;
        slow = slow->next;
    };
    
    return fast;
}
