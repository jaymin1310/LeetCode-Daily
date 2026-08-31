class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* nextn = curr->next;

        int first = -1;
        int last = -1;
        int cnt = 1;
        int mindist = INT_MAX;

        while (nextn) {

            if ((curr->val > prev->val && curr->val > nextn->val) ||
                (curr->val < prev->val && curr->val < nextn->val)) {

                if (first == -1) {
                    first = cnt;
                }

                if (last != -1) {
                    mindist = min(mindist, cnt - last);
                }

                last = cnt;
            }

            cnt++;
            prev = curr;
            curr = nextn;
            nextn = nextn->next;
        }

        if (mindist == INT_MAX)
            return {-1, -1};

        return {mindist, last - first};
    }
};