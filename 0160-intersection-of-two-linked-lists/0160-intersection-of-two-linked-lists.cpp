/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        int cnt1=0,cnt2=0;
        while(temp1 && temp2){
            cnt1++;
            cnt2++;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        while(temp1){
            cnt1++;
            temp1=temp1->next;
        }
        while(temp2){
            cnt2++;
            temp2=temp2->next;
        }
        int diff=cnt1-cnt2;
        if(diff<0){
            while(diff++ != 0) headB = headB->next; 
        }
        else while(diff-- != 0) headA = headA->next;
        while(headA != NULL) {
            if(headA == headB) return headA;
            headB = headB->next;
            headA = headA->next;
        }
        return NULL;

    }
};