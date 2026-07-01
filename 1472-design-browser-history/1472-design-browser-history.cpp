struct Node{
    string data;
    Node* next;
    Node* prev;
    Node(string x){
        data=x;
        next=nullptr;
        prev=nullptr;
    }
};
class BrowserHistory {
    Node* head;
    Node* traverse;
    void clearAll(Node* temp){
        while(temp){
            Node* nextNode=temp->next;
            delete temp;
            temp=nextNode;
        }
    }
public:
    BrowserHistory(string homepage) {
        head=new Node(homepage);
        traverse=head;
    }
    
    void visit(string url) {
        clearAll(traverse->next);
        traverse->next=nullptr;
        Node* newNode=new Node(url);
        traverse->next=newNode;
        newNode->prev=traverse;
        traverse=traverse->next;
    }
    
    string back(int step) {
        while((step--) && traverse->prev){
            traverse=traverse->prev;
        }
        return traverse->data;
    }
    
    string forward(int step) {
        while((step--) && traverse->next){
            traverse=traverse->next;
        }
        return traverse->data;
    }
     ~BrowserHistory() {
        clearAll(head);
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */