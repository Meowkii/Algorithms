#include <bits/stdc++.h>

using namespace std;
typedef long long int64;

#define INF (int)(1e9+7)

vector<vector<pair<int64, int>>> adj;

tuple<vector<int>, int64> prim(int s = 0) {
    int n = (int) adj.size();
    vector<int64> d(n, INF);
    vector<int> tree(n, -1);
    int64 cost = 0;
    priority_queue<pair<int64, int>, vector<pair<int64, int>>, greater<>> pq;
    pq.emplace(d[s] = 0, s);
    while (!pq.empty()) {
        auto[c, u] = pq.top();
        pq.pop();
        if (d[u] != c) continue;
        cost += c;
        for (auto[uv, v]: adj[u]) {
            if (d[v] > uv) {
                d[v] = uv;
                tree[v] = u;
                pq.emplace(uv, v);
            }
        }
    }
    return {tree, cost};
}
