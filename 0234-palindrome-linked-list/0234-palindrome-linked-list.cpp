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
    ListNode* reverse(ListNode* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* newnode=reverse(head->next);
        ListNode* front=head->next;
        front->next=head;
        head->next=NULL;
        return newnode;
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
        ListNode* newn=reverse(slow);
        fast=head;
        while(newn!=NULL){
            if(fast->val!=newn->val){
                reverse(slow);
                return false;
            }
            newn=newn->next;
            fast=fast->next;
        }
        reverse(slow);
        return true;
    }
};