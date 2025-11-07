class StockSpanner {
public:
    stack<int>st;
    vector<int>arr;
    int ind;
    StockSpanner() {
        ind=0;
    }
    int next(int price) {
        arr.push_back(price);
        while(!st.empty() && arr[st.top()]<=price){
            st.pop();
        }
        int pg=(st.empty())?-1:st.top();
        st.push(arr.size()-1);
        return (arr.size()-1)-pg;
    }
};

/**st
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */