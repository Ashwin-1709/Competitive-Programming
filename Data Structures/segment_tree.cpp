struct seg_tree {
    int n;
    typedef int item;
    vector<item> tree;
    const item NEUTRAL_ELEMENT = 0;
    item merge(item a, item b) {
        return a + b;
    }
    item single(int a) {
        return a;
    }
    void init(int n) {
        this->n = n;
        tree.resize(2 * n);
    }
    void build(vector<int>& a) {
        for (int i = 0; i < n; i++)
            tree[n + i] = single(a[i]);
        for (int i = n - 1; i > 0; --i)
            tree[i] = merge(tree[i << 1], tree[i << 1 | 1]);
    }
    void update(int p, int value) {
        tree[p + n] = single(value);
        p += n;
        for (int i = p; i > 1; i >>= 1)
            tree[i >> 1] = merge(tree[i], tree[i ^ 1]);
    }
    item query(int l, int r) {
        item res = NEUTRAL_ELEMENT;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1)
                res = merge(res, tree[l++]);
            if (r & 1)
                res = merge(res, tree[--r]);
        }
        return res;
    }
};
