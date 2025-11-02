class Solution {
public:
//nse
 vector<int> nextSE(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        vector<int> res(n, n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (!st.empty()) res[i] = st.top();
            st.push(i);
        }
        return res;
    }
//psee
    vector<int> previousSE(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        vector<int> res(n, -1);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            if (!st.empty()) res[i] = st.top();
            st.push(i);
        }
        return res;
    }
    //nge
    vector<int> nextGE(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        vector<int> res(n, n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            if (!st.empty()) res[i] = st.top();
            st.push(i);
        }
        return res;
    }
    //pgee
    vector<int> previousGE(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        vector<int> res(n, -1);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            if (!st.empty()) res[i] = st.top();
            st.push(i);
        }
        return res;
    }
    long long subArrayRanges(vector<int>& arr) {
        int n = arr.size();
        long long minTot = 0;
        long long maxTot=0;
        vector<int> pse = previousSE(arr);
        vector<int> nse = nextSE(arr);
        vector<int> nge = nextGE(arr);
        vector<int> pge = previousGE(arr);
        long long ans=0;
        for (int i = 0; i < n; i++) {
            long long minLeft = i - pse[i];
            long long minRight = nse[i] - i;
            long long maxLeft = i - pge[i];
            long long maxRight = nge[i] - i;
            minTot += (1LL * minLeft * minRight)* arr[i];
            maxTot +=(1LL * maxLeft * maxRight)* arr[i];
        }

        return maxTot-minTot;
    }
};