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
    ListNode* reverseHalf(ListNode* slow){
        ListNode* prev=nullptr;
        ListNode* curr=slow;
        while(curr){
            ListNode* after=curr->next;
            curr->next=prev;
            prev=curr;
            curr=after;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prevNode=head;
        while(fast){
            prevNode=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* revHead=reverseHalf(slow);
        ListNode* left=head;
        ListNode* right=revHead;
        int ans=0;
        while(left && right){
            ans=max(ans,left->val+right->val);
            left=left->next;
            right=right->next;
        }
        prevNode->next=reverseHalf(revHead);
        return ans;
    }
};