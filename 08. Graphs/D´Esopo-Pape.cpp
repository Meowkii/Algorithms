#include <bits/stdc++.h>

using namespace std;
typedef long long int64;

#define INF (int) (1e9+7)

vector<vector<pair<int64, int>>> adj;

void depape(int s, vector<int64> &d, vector<int> &p) {
    int n = (int) adj.size();
    d.assign(n, INF);
    p.assign(n, -1);
    vector<int> status(n, 2);
    deque<int> dq;
    d[s] = 0;
    dq.push_front(s);
    while (!dq.empty()) {
        int u = dq.front();
        dq.pop_front();
        status[u] = 0;
        for (auto[uv, v]: adj[u]) {
            if (d[u] + uv < d[v]) {
                d[v] = d[u] + uv;
                p[v] = u;
                if (status[v] == 2) {
                    status[v] = 1;
                    dq.push_back(v);
                } else if (status[v] == 0) {
                    status[v] = 1;
                    dq.push_front(v);
                }
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
