#include <bits/stdc++.h>

using namespace std;
typedef long long int64;

#define INF (int) (1e9+7)

vector<vector<pair<int64, int>>> adj;

bool spfa(int s, vector<int64> &d, vector<int> &p) {
    int n = (int) adj.size();
    d.assign(n, INF);
    p.assign(n, -1);
    vector<int> cnt(n, 0);
    vector<bool> inqueue(n, false);
    queue<int> q;
    d[s] = 0;
    q.push(s);
    inqueue[s] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inqueue[u] = false;
        for (auto[uv, v]: adj[u]) {
            if (d[u] + uv < d[v]) {
                d[v] = d[u] + uv;
                p[v] = u;
                if (!inqueue[v]) {
                    q.push(v);
                    inqueue[v] = true;
                    ++cnt[v];
                    if (cnt[v] > n) return false;
                }
            }
        }
    }
    return true;
}

vector<int> trace(int t, const vector<int> &p) {
    vector<int> path;
    for (int i = t; i != -1; i = p[i]) path.push_back(i);
    reverse(path.begin(), path.end());
    return path;
}
