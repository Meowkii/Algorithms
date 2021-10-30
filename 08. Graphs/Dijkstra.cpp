#include <bits/stdc++.h>

using namespace std;
typedef long long int64;

#define INF (int) (1e9 + 7)

vector<vector<pair<int64, int>>> adj;
vector<bool> used;

void dijkstra(int s, vector<int64> &d, vector<int> &p) {
    int n = (int) adj.size();
    d.assign(n, INF);
    p.assign(n, -1);
    used.assign(n, false);
    d[s] = 0;
    for (int i = 0; i < n; ++i) {
        int u = -1;
        for (int j = 0; j < n; ++j) if (!used[j] && (u == -1 || d[j] < d[u])) u = j;
        if (d[u] == INF) break;
        used[u] = true;
        for (auto[uv, v]: adj[u]) {
            if (d[v] + uv < d[v]) {
                d[v] = d[v] + uv;
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
