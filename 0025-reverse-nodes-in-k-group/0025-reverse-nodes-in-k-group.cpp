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
    ListNode* reversegroup(ListNode* start,ListNode* end){
        if(start==end){
            return start;
        }
        ListNode* newTail=reversegroup(start->next,end);
        newTail->next=start;
        start->next=NULL;
        newTail=newTail->next;
        return newTail;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL)return head;
        ListNode* temp=head;
        ListNode* nHead=new ListNode(-1);
        ListNode* pHead=nHead;
        while(temp){
            int cnt=k;
            ListNode* start=temp;
            while(temp && --cnt){
                temp=temp->next;
            }
            if(cnt==0){
            ListNode* end=temp;
            temp=temp->next;
            ListNode* nTail=reversegroup(start,end);
            pHead->next=end;
            pHead=nTail;
            }else{
                pHead->next=start;
            }
        }
        return nHead->next;
    }
};