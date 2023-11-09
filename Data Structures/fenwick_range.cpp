// point query
template<typename T>
struct fenwick_tree {
    vector<T> bit;
    int n;
    fenwick_tree(int n) {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }
    T sum(int idx) {
        T ret{};
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }
    T sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
    void add(int idx, T delta) {
        for (++idx; idx < n; idx += idx & -idx)
            bit[idx] += delta;
    }
    void update(int l, int r, T val) {
        add(l, val);
        add(r + 1, -val);
    }
    T point(int idx) {
        T ret{};
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }
};
