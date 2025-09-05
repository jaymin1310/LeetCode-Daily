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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* prev=head;
        if(head==NULL || head->next==NULL ||head->next->next==NULL)return head;
        ListNode* curr=NULL;
        ListNode* temp;
        ListNode* even=head->next;
        int cnt=0;
        while(prev->next!=NULL){
            curr=prev->next;
            prev->next=curr->next;
            if(cnt%2==0){
                (prev->next==NULL)?temp=prev:temp=prev->next;
            }
            prev=curr;
            cnt++;
        }
        temp->next=even;
        return head;
    }
};