#include <bits/stdc++.h>

using namespace std;
typedef long long int64;

vector<vector<int>> adj;
vector<bool> used;
vector<int> tin, low;
vector<int> cutpoints;
int n;
int timer;

void dfs(int v, int p = -1) {
    used[v] = true;
    tin[v] = low[v] = timer++;
    int child = 0;
    for (int to: adj[v]) {
        if (to == p) continue;
        if (!used[to]) low[v] = min(low[v], tin[to]);
        else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v] && p != -1) cutpoints.emplace_back(v);
            ++child;
        }
    }
    if (p == -1 && child > 1) cutpoints.emplace_back(v);
}

// search cutpoints
void scp() {
    timer = 0;
    used.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) if (!used[i]) dfs(i);
}
