#include <bits/stdc++.h>

using namespace std;

template<class T>
struct minstack {
    stack<pair<T, T>> st;

    void push(T value) {
        // current min
        T cmin = st.empty() ? value : min(st.top().second, value);
        st.push({value, cmin});
    }

    T getmin() {
        return st.top().second;
    }

    void pop() {
        st.pop();
    }
};
