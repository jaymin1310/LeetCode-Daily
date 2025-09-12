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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* start=head;
        if(head==NULL || head->next==NULL)return head;
        ListNode* end=head;
        int cnt=0;
        while(end!=NULL && end->next!=NULL){
            cnt++;
            start=start->next;
            end=end->next->next;
        }
        int size=(end)?(2*cnt+1):(2*cnt);
        k=k%size;
        if(k==0)return head;
        start=head;
        end=head;
        while(--k){
            end=end->next;
        }
        ListNode* prev=head;
        while(end->next){
            prev=start;
            start=start->next;
            end=end->next;
        }
        prev->next=NULL;
        end->next=head;
        return start;

    }
};