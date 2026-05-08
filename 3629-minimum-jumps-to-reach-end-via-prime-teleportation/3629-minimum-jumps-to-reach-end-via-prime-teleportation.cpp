class Solution {
public:
    static int total;
    static vector<int> spf;
    static bool isInitialized;
    void static seive() {
        for (int i = 0; i < total; i++)
            spf[i] = i;
        for (int i = 2; i * i < total; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j < total; j += i) {
                    if (spf[j] == j) {
                        spf[j] = i;
                    }
                }
            }
        }
    }
    int minJumps(vector<int>& nums) {
        if (!isInitialized) {
            seive();
            isInitialized = true;
        }
        int n = nums.size();
        unordered_map<int, vector<int>> primefact;
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            unordered_set<int> st;
            while (x > 1) {
                st.insert(spf[x]);
                x /= spf[x];
            }
            for (auto& fact : st) {
                primefact[fact].push_back(i);
            }
        }
        queue<int> qu;
        vector<bool> vis(n, false);
        qu.push(0);
        vis[0] = 1;
        int cnt = 0;
        while (!qu.empty()) {
            int size = qu.size();
            while (size--) {
                int front = qu.front();
                qu.pop();
                if (front == n - 1)
                    return cnt;
                if (front + 1 < n && !vis[front + 1]) {
                    vis[front+1] = 1;
                    qu.push(front + 1);
                }
                if (front - 1 >= 0 && !vis[front - 1]) {
                    vis[front-1] = 1;
                    qu.push(front - 1);
                }
                int x = nums[front];
                if (spf[x] == x) {
                    for (auto& idx : primefact[x]) {
                        if (!vis[idx]) {
                            vis[idx] = true;
                            qu.push(idx);
                        }
                    }
                    primefact[x].clear();
                }
            }
            cnt++;
        }
        return -1;
    }
};
int Solution::total = 1e6 + 1;
vector<int> Solution::spf(1e6 + 1);
bool Solution::isInitialized = false;