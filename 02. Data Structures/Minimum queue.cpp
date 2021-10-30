#include <bits/stdc++.h>

using namespace std;

template<class T>
struct minqueue {
    stack<pair<T, T>> u, v;

    void push(T value) {
        // current min
        T cmin = u.empty() ? value : min(u.top().second, value);
        u.push({value, cmin});
    }

    void pop() {
        if (v.empty()) {
            while (!u.empty()) {
                T value = u.top().first;
                u.pop();
                T cmin = v.empty() ? value : min(v.top().second, value);
                v.push({value, cmin});
            }
        }
        v.pop();
    }

    T getmin() {
        if (!u.empty() && !v.empty()) return min(u.top().second, v.top().second);
        else if (!u.empty()) return u.top().second;
        else return v.top().second;
    }
};
