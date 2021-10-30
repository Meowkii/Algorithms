#include <bits/stdc++.h>

using namespace std;

template<class T>
struct sumfenwick {
    vector<T> ar;
    int n;
    vector<T> bit;

    explicit sumfenwick(vector<T> &ar) {
        this->ar = ar;
        n = (int) ar.size();
        bit.assign(n, 0);
        init();
    }

    void init() {
        for (int i = 0; i < n; ++i) add(i, ar[i]);
    }

    void add(int id, T delta) {
        for (int i = id; i < n; i = i | (i + 1)) bit[i] += delta;
    }

    T sum(int r) {
        T _sum = 0;
        for (int i = r; 0 <= i; i = (i & (i + 1)) - 1) _sum += bit[i];
        return _sum;
    }

    T rsq(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};

template<class T>
struct minfenwick {
    vector<T> ar;
    int n;
    vector<T> bit;
    const T INF = 1e9 + 7;

    explicit minfenwick(vector<T> &ar) {
        this->ar = ar;
        n = (int) ar.size();
        bit.assign(n, INF);
        init();
    }

    void init() {
        for (int i = 0; i < n; ++i) update(i, ar[i]);
    }

    T fmin(int r) {
        T _min = INF;
        for (int i = r; 0 <= i; i = (i & (i + 1)) - 1) _min = min(_min, bit[i]);
        return _min;
    }

    void update(int id, T value) {
        for (int i = id; i < n; i = i | (i + 1)) bit[i] = min(bit[i], value);
    }
};
