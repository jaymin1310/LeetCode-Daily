/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNod; *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* temp=head;
        unordered_set<ListNode*>st;
        while(temp!=NULL){
            if(st.find(temp)!=st.end()){
                return temp;
            }
            st.insert(temp);
            temp=temp->next;
        }
        return NULL;
    }
};