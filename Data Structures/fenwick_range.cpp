// point query
struct fenwick_tree {
    vector<int> BIT;
    int n;
    fenwick_tree(int n) {
        this->n = n + 1;
        BIT.assign(n + 1, 0);
    }
    int sum(int i) {
        int ret = 0;
        for (++i; i > 0; i -= i & -i)
            ret += BIT[i];
        return ret;
    }
    void update(int i, int delta) {
        for (++i; i < n; i += i & -i)
            BIT[i] += delta;
    }
    void range(int l, int r, int val) {
        update(l, val);
        update(r + 1, -val);
    }
};
