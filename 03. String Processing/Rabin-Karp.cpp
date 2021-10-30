#include <bits/stdc++.h>

using namespace std;
typedef long long int64;

vector<int> rabin_karp(const string &s, const string &t) {
    const int p = 31;
    const int m = 1e9 + 7;
    int ns = (int) s.size();
    int nt = (int) t.size();
    vector<int64> powers(max(ns, nt));
    powers[0] = 1;
    for (int i = 1; i < (int) powers.size(); ++i) powers[i] = (powers[i - 1] * p) % m;
    vector<int64> phs(nt + 1);
    for (int i = 0; i < nt; ++i) phs[i + 1] = (phs[i] + (t[i] - 'a' + 1) * powers[i]) % m;
    int64 hs = 0;
    for (int i = 0; i < ns; ++i) hs = (hs + (s[i] - 'a' + 1) * powers[i]) % m;
    vector<int> occurs;
    for (int i = 0; i < nt - ns + 1; ++i) {
        int64 hc = (phs[i + ns] - phs[i] + m) % m;
        if (hc == hs * powers[i] % m) occurs.push_back(i);
    }
    return occurs;
}
