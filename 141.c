/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) 
{
    struct ListNode *fast, *slow;
    
    fast = slow = head;
    do {
        if (fast && fast->next) {
            fast = fast->next->next;
        } else {
            return false;
        }
        
        slow = slow->next;
    } while (fast != slow);

    return true;
}
