#include <bits/stdc++.h>

using namespace std;
typedef long long int64;

vector<vector<int>> adj, radj, sccomponents; // reversed adj
vector<bool> used;
vector<int> order;
int n;

void dfs(int u) {
    used[u] = true;
    for (int v: adj[u]) if (!used[v]) dfs(v);
    order.push_back(u);
}

void rdfs(int u) {
    used[u] = true;
    sccomponents.back().push_back(u);
    for (int v: radj[u]) if (!used[v]) rdfs(v);
}

// search strongly connected sccomponents
void sscc() {
    used.assign(n, false);
    for (int i = 0; i < n; ++i) if (!used[i]) dfs(i);
    used.assign(n, false);
    reverse(order.begin(), order.end());
    for (int u: order) {
        if (!used[u]) {
            sccomponents.emplace_back();
            rdfs(u);
        }
    }
}
