class MyStack {
    queue<int> qe1,qe2;
public:
    MyStack() {}
    void push(int x) {
         qe2.push(x); 
         while(!qe1.empty()){
            qe2.push(qe1.front());
            qe1.pop();
        }
        swap(qe1,qe2);
    }
    int pop() {
        int x=qe1.front();
        qe1.pop();
        return x;
    }

    int top() {
        return qe1.front();
    }

    bool empty() {
        if (qe1.empty())
            return true;
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * bool pint param_2 = aram_4 = obj->empty();
 */