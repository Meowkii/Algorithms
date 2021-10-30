#include <bits/stdc++.h>

using namespace std;
typedef long long int64;

#define INF (int) (1e9+7)

vector<vector<pair<int64, int>>> adj;

void bfsdijkstra(int s, vector<int64> &d, vector<int> &p) {
    int n = (int) adj.size();
    d.assign(n, INF);
    p.assign(n, -1);
    d[s] = 0;
    deque<int> dq;
    dq.push_front(s);
    while (!dq.empty()) {
        int u = dq.front();
        dq.pop_front();
        for (auto[uv, v]: adj[u]) {
            if (d[u] + uv < d[v]) {
                d[v] = d[u] + uv;
                if (uv == 1) dq.push_back(v);
                else dq.push_front(v);
                p[v] = u;
            }
        }
    }
}

vector<int> trace(int t, const vector<int> &p) {
    vector<int> path;
    for (int i = t; i != -1; i = p[i]) path.push_back(i);
    reverse(path.begin(), path.end());
    return path;
}
