#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<bool> used;
vector<vector<int>> sccomponents;
int n;

void dfs(int u) {
    used[u] = true;
    sccomponents.back().push_back(u);
    for (int v: adj[u]) if (!used[v]) dfs(v);
}

// search connected sccomponents
void scc() {
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            sccomponents.emplace_back();
            dfs(i);
        }
    }
}
