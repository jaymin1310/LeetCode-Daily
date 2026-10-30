class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {

        vector<vector<pair<int,int>>> adj(n);

        for (auto &it : edges) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        if (n == 1) return 0;

        vector<vector<int>> dist(n, vector<int>(k + 1, INT_MAX));

        // {cost, node, consecutive count}
        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
        > pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {

            auto [cost, node, cont] = pq.top();
            pq.pop();

            if (cost != dist[node][cont])
                continue;

            if (node == n - 1)
                return cost;

            for (auto &[next, weight] : adj[node]) {

                int newCont;

                if (labels[node] == labels[next]) {
                    newCont = cont + 1;
                } else {
                    newCont = 1;
                }

                if (newCont > k)
                    continue;

                int newCost = cost + weight;

                if (newCost < dist[next][newCont]) {

                    dist[next][newCont] = newCost;

                    pq.push({
                        newCost,
                        next,
                        newCont
                    });
                }
            }
        }

        return -1;
    }
};