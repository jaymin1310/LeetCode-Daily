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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow=head;
        ListNode* fast=head;
        if(head==NULL || head->next==NULL)return NULL;
        int size=0;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            size++;
        }
        size=(fast!=NULL)?2*size+1:2*size;
        int del=size-n;
        ListNode* temp=head;
        if(del==0){
            head=temp->next;
            delete temp;
            temp=head;
            return head;
        }
        while(del!=1){
            temp=temp->next;
            del--;
        }
        ListNode* delet=temp->next;
        temp->next=temp->next->next;
        delete delet;
        return head;
    }
};