#include <bits/stdc++.h>

using namespace std;
typedef long long int64;

int64 binpow(int64 a, int64 b) {
    int64 ans = 1;
    while (b > 0) {
        if (b & 1) ans *= a;
        a *= a;
        b >>= 1;
    }
    return ans;
}

int64 binpowmod(int64 a, int64 b, int64 m = 1e9 + 7) {
    int64 ans = 1;
    a %= m;
    while (b > 0) {
        if (b & 1) ans = ans * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return ans;
}
