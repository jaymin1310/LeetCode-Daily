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
    ListNode* merge(ListNode* left,ListNode* right){
        ListNode* head=NULL;
        ListNode* temp=head;
        while(left!=NULL && right!=NULL){
            if(right->val>left->val){
                if(head==NULL){
                    head=left;temp=head;
                }
                else{
                    temp->next=left;
                    temp=temp->next;
                }
                left=left->next;
            }else{
                if(head==NULL){
                    head=right;temp=right;
                }
                else{
                    temp->next=right;
                    temp=temp->next;
                }
                right=right->next;
            }
        }
            while(left!=NULL){
                temp->next=left;
                temp=temp->next;
                left=left->next;
            }
            while(right!=NULL){
                temp->next=right;
                temp=temp->next;
                right=right->next;
            }
        return head;
    }
    ListNode* middleNode(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* mid=middleNode(head);
        ListNode* right=mid->next;
        mid->next=NULL;
        ListNode* left=head;
        left=sortList(left);
        right=sortList(right);
       return merge(left,right);
    }
};