class MinStack {
public:
    stack<long long>st;
    long long mini;
    MinStack() {
        while(!st.empty()){
            st.pop();
        }
        mini=LLONG_MAX;
    }
    
    void push(int val) {
         if(st.empty()){
            mini=val;
            st.push(val);
         }else{
            if(val<mini){
                st.push(2LL*val-mini);
                mini=val;
            }else{
                st.push(val);
            }
         }
    }
    
    void pop() {
        if(st.empty())return;
        long long el=st.top();
        if(el<mini){
            mini=2*mini-el;
        }
        st.pop();
    }
    
    int top() {
        long long el=st.top();
        if(el<mini){
            return mini;
        }return el;
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */