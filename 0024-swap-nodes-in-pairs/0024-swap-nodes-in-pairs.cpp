class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        while (prev->next && prev->next->next) {
            ListNode* a = prev->next;
            ListNode* b = a->next;

            // Swapping
            a->next = b->next;
            b->next = a;
            prev->next = b;

            // Move prev to next pair
            prev = a;
        }

        return dummy.next;
    }
};
