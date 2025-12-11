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
        auto comp=[](ListNode* a,ListNode* b){
            return a->val > b->val;
        };
        ListNode* head=new ListNode(-1);
        priority_queue<ListNode*,vector<ListNode*>,decltype(comp)>pq(comp);
        int k=lists.size();
        for(int i=0;i<k;i++){
            if(lists[i])pq.push(lists[i]);
        }
        ListNode* traverse=head;
        while(!pq.empty()){
            traverse->next=pq.top();
            if(pq.top()->next)pq.push(pq.top()->next);
            pq.pop();
            traverse=traverse->next;
        }
        return head->next;
    }
};