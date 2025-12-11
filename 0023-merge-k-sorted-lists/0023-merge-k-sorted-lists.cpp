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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head=new ListNode(-1);
        priority_queue<int,vector<int>,greater<int>>pq;
        int k=lists.size();
        for(int i=0;i<k;i++){
            ListNode* thead=lists[i];
            while(thead!=NULL){
                pq.push(thead->val);
                thead=thead->next;
            }
        }
        ListNode* traverse=head;
        while(!pq.empty()){
            ListNode* newn=new ListNode(pq.top());
            traverse->next=newn;
            traverse=traverse->next;
            pq.pop();
        }
        return head->next;
    }
};