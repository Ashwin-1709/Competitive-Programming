// point query
struct fenwick_tree {
    vector<int> bit; 
    int n;
    fenwick_tree(int n) {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }
    int sum(int idx) {
        int ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }
    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
    void add(int idx, int delta) {
        for (++idx; idx < n; idx += idx & -idx)
            bit[idx] += delta;
    }
    void update(int l, int r, int val) {
        add(l, val);
        add(r + 1, -val);
    }
    int point(int idx) {
        int ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }
};
