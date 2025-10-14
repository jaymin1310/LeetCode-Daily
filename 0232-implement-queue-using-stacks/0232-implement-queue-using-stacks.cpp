class MyQueue {
    stack<int>st1;
    stack<int>st2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        st2.push(x);
    }
    
    int pop() {
        if(st1.empty()){
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
        }
        int x=st1.top();
        st1.pop();
        return x;
    }  
    int peek() {
        if(st1.empty()){
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
        }
        return st1.top();
    }
    
    bool empty() {
        if(st1.empty() && st2.empty())return true;
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */