
/** 
Approach-3 : Using Reverse LinkedList
Time Complexity : O(N)
Space Complexity : O(1)
*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* tail = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;

        return tail;
    }

    ListNode* removeNodes(ListNode* head) {
        head = reverseList(head);
        int maxNode = -1;
        
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL) {
            maxNode = max(maxNode, curr->val);

            if(curr->val < maxNode) {
                prev->next = curr->next;
                ListNode* temp = curr;
                curr = curr->next;
                delete(temp);
            }
            else {
                prev = curr;
                curr = curr->next;
            }
        }
        return reverseList(head);
    }
};