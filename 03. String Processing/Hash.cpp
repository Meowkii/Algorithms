#include <bits/stdc++.h>

using namespace std;
typedef long long int64;

int64 hash(const string &s) {
    const int p = 31;
    const int m = 1e9 + 7;
    int64 power = 1;
    int64 hashed = 0;
    for (char c: s) {
        hashed = (hashed + power * (c - 'a' + 1)) % m;
        power = (power * p) % m;
    }
    return hashed;
}
