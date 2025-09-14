/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)return NULL;
        Node* temp=head;
        while(temp){
            Node* cnode=new Node(temp->val);
            cnode->next=temp->next;
            temp->next=cnode;
            temp=temp->next->next;
        }
        temp=head;
        while(temp){
            temp->next->random=(temp->random)?temp->random->next:temp->random;
            temp=temp->next->next;
        }
        Node* first=head;
        Node* chead=head->next;
        Node* second=chead;
        while(first){
            first->next=first->next->next;
            second->next=(second->next)?second->next->next:second->next;
            first=first->next;
            second=second->next;
        }
        return chead;
    }
};