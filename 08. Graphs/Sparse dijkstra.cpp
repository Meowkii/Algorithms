#include <bits/stdc++.h>

using namespace std;
typedef long long int64;

#define INF (int) (1e9 + 7)

vector<vector<pair<int64, int>>> adj;

void setdijkstra(int s, vector<int64> &d, vector<int> &p) {
    int n = (int) adj.size();
    d.assign(n, INF);
    p.assign(n, -1);
    d[s] = 0;
    set<pair<int64, int>> st;
    st.insert({d[s], s});
    while (!st.empty()) {
        int u = st.begin()->second;
        st.erase(st.begin());
        for (auto[uv, v]: adj[u]) {
            if (d[u] + uv < d[v]) {
                st.erase({d[v], v});
                d[v] = d[u] + uv;
                st.insert({d[v], v});
                p[v] = u;
            }
        }
    }
}

void pqdijkstra(int s, vector<int64> &d, vector<int> &p) {
    int n = (int) adj.size();
    d.assign(n, INF);
    p.assign(n, -1);
    d[s] = 0;
    priority_queue<pair<int64, int>, vector<pair<int64, int>>, greater<>> pq;
    pq.push({d[s], s});
    while (!pq.empty()) {
        int u = pq.top().second;
        int64 du = pq.top().first;
        pq.pop();
        if (du != d[u]) continue;
        for (auto[uv, v]: adj[u]) {
            if (d[u] + uv < d[v]) {
                d[v] = d[u] + uv;
                pq.push({d[v], v});
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
