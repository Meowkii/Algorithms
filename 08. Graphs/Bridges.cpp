#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<bool> used;
vector<int> tin, low;
vector<pair<int, int>> bridges;
int n;
int timer;

void dfs(int v, int p = -1) {
    used[v] = true;
    tin[v] = low[v] = timer++;
    for (int to: adj[v]) {
        if (to == p) continue;
        if (used[to]) low[v] = min(low[v], tin[to]);
        else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v]) bridges.emplace_back(v, to);
        }
    }
}

// search bridges
void sbs() {
    timer = 0;
    used.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) if (!used[i]) dfs(i);
}
