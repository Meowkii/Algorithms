#include <bits/stdc++.h>

using namespace std;

vector<int> kmp(string &s, string &t) {
    // prefix function
    int ns = (int) s.length();
    vector<int> pi(ns);
    for (int i = 1, j = 0; i < ns; ++i) {
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) ++j;
        pi[i] = j;
    }
    // kmp
    int nt = (int) t.length();
    vector<int> pos;
    for (int i = 0, j = 0; i < nt; ++i) {
        while (j > 0 && s[j] != t[i]) j = pi[j - 1];
        if (s[j] == t[i]) ++j;
        if (j == ns) {
            pos.push_back(i - ns + 1);
            j = pi[j - 1];
        }
    }
    return pos;
}
