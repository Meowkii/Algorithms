#include <bits/stdc++.h>

using namespace std;
typedef long long int64;

#define INF (int)(1e9 + 7)

struct edge {
    int u;
    int v;
    int64 uv;
};

int n, m;
vector<edge> edges;

void bford(int s, vector<int64> &d, vector<int> &p) {
    d.assign(n, INF);
    p.assign(n, -1);
    d[s] = 0;
    for (int i = 0; i < n - 1; ++i) {
        bool ok = true;
        for (int j = 0; j < m; ++j) {
            if (d[edges[j].u] < INF && d[edges[j].u] + edges[j].uv < d[edges[j].v]) {
                d[edges[j].v] = d[edges[j].u] + edges[j].uv;
                p[edges[j].v] = edges[j].u;
                ok = false;
            }
        }
        if (ok) break;
    }
}

vector<int> trace(int t, const vector<int> &p) {
    vector<int> path;
    for (int i = t; i != -1; i = p[i]) path.push_back(i);
    reverse(path.begin(), path.end());
    return path;
}
