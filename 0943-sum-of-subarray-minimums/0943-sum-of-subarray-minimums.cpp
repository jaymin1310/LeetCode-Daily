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

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long res = 0;
        int MOD = 1e9 + 7;
        vector<int> pse = previousSE(arr);
        vector<int> nse = nextSE(arr);

        for (int i = 0; i < n; i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;
            long long Tot = (1LL * left * right) % MOD * arr[i] % MOD;
            res = (res + Tot) % MOD;
        }

        return (int)((res + MOD) % MOD);
    }
};
