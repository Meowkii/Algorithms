#include <bits/stdc++.h>

using namespace std;

template<class T>
struct sptrsq {
    int n;
    int k;
    vector<T> ar;
    vector<vector<T>> spt;

    explicit sptrsq(vector<T> &ar) {
        n = (int) ar.size();
        k = ceil(log2(n));
        this->ar = ar;
        this->spt.assign(n, vector<T>(k + 1));
        init();
    }

    void init() {
        for (int i = 0; i < n; ++i) spt[i][0] = ar[i];
        for (int j = 1; j <= k; ++j) {
            for (int i = 0; i + (1 << j) <= n; ++i) {
                spt[i][j] = spt[i][j - 1] + spt[i + (1 << (j - 1))][j - 1];
            }
        }
    }

    T rsq(int l, int r) {
        assert(l <= r);
        T sum = 0;
        for (int i = k; i >= 0; --i) {
            if ((1 << i) <= r - l + 1) {
                sum += spt[l][i];
                l += (1 << i);
            }
        }
        return sum;
    }
};

template<class T>
struct sptrmq {
    int n;
    int k;
    vector<T> ar;
    vector<T> plog;
    vector<vector<T>> spt;

    explicit sptrmq(vector<T> &ar) {
        n = (int) ar.size();
        k = (int) (log2(n) + 0.5);
        this->ar = ar;
        this->plog.assign(n + 1, 0);
        this->spt.assign(n, vector<T>(k + 1));
        init();
    }

    void init() {
        for (int i = 2; i <= n; ++i) plog[i] = plog[i / 2] + 1;
        for (int i = 0; i < n; ++i) spt[i][0] = ar[i];
        for (int j = 1; j <= k; ++j) {
            for (int i = 0; i + (1 << j) <= n; ++i) {
                spt[i][j] = min(spt[i][j - 1], spt[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    T rmq(int l, int r) {
        assert(l <= r);
        int i = plog[r - l + 1];
        return min(spt[l][i], spt[r - (1 << i) + 1][i]);
    }
};
