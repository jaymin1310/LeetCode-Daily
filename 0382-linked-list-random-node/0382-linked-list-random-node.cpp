class Solution {
public:
    ListNode* head;

    Solution(ListNode* head) {
        this->head = head;
    }
    
    int getRandom() {
        int res = 0;      // chosen value
        int count = 0;    // node index
        
        ListNode* cur = head;
        while (cur != nullptr) {
            count++;
            // choose current node with probability 1/count
            if (rand() % count == 0) {
                res = cur->val;
            }
            cur = cur->next;
        }
        return res;
    }
};
