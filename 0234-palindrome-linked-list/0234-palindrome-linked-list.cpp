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
    bool recursion(ListNode*& temp, ListNode* start) {
    if (start == NULL) return true;
    bool isPal = recursion(temp, start->next);
    if (!isPal) return false;
    if (start->val != temp->val) return false;
    temp = temp->next;
    return true;
   }
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL)return head;
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast!=NULL)slow=slow->next;
        return recursion(head,slow);
    }
};