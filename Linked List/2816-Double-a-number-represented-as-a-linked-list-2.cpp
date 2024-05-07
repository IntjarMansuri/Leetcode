
// Approach : 1 (Using Recursion)
// T.C : O(N)
// S.C : O(N)


class Solution {
public:
    int doubleUtility(ListNode* head) {
        if(head == NULL) {
            return 0;
        }

        int carry = doubleUtility(head->next);
        int newValue = (head->val)*2 + carry;
        head->val = newValue%10;

        return newValue/10;

    }
    ListNode* doubleIt(ListNode* head) {
        int lastCarry = doubleUtility(head);

        if(lastCarry > 0) {
            ListNode* newHead = new ListNode(lastCarry);
            newHead->next = head;
            return newHead;
        }

        return head;
    }
};