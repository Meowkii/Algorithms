#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<bool> used;

void dfs(int u) {
    used[u] = true;
    for (int v: adj[u]) if (!used[v]) dfs(v);
}
