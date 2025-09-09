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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* tempHead=new ListNode(-1);
        ListNode* temp=tempHead;
        int carry=0;
        while(l1 || l2){
            int sum=carry+((l1)?l1->val:0)+((l2)?l2->val:0);
            ListNode* temperNode=new ListNode(sum);
            temp->next=temperNode;
            temp=temp->next;
            if(temp->val>=10){
                carry=1;
                temp->val=temp->val%10;
            }else{
                carry=0;
            }
            if(l1)l1=l1->next;
            if(l2)l2=l2->next;
        }
        if(carry==1){ListNode* newN=new ListNode(1);
        temp->next=newN;}
        return tempHead->next;
    }
};