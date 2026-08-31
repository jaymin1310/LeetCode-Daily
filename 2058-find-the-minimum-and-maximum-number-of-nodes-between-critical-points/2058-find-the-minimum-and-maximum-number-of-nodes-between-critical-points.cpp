/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev = head;
        ListNode* curr = (head->next) ? head->next : nullptr;
        ListNode* nextn = (curr) ? curr->next : nullptr;
        if (!nextn)
            return {-1, -1};
        int lower = -1, higher = -1;
        int cnt = 1, mindist = INT_MAX;
        while (nextn) {
            if (((curr->val > prev->val) && (curr->val > nextn->val)) ||
                ((curr->val < prev->val) && (curr->val < nextn->val))) {
                cout << cnt << " ";
                if (lower == -1)
                    lower = cnt;
                if (higher != -1) {
                    mindist = min(mindist, cnt - higher);
                }
                higher = cnt;
            }
            cnt++;
            prev = curr;
            curr = nextn;
            nextn = nextn->next;
        }
        if (mindist == INT_MAX)
            return {-1, -1};
        return {mindist, higher - lower};
    }
};