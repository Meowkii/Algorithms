#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
int n;
int s;

void bfs() {
    queue<int> q;
    vector<bool> used(n);

    q.push(s);
    used[s] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v: adj[u]) {
            if (!used[v]) {
                used[v] = true;
                q.push(v);
            }
        }
    }
}
