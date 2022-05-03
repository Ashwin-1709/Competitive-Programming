// 1 Based indexing
struct fenwick_tree
{
    int size;
    vector<int> tree;
    fenwick_tree(int n) {
        size = n;
        tree.assign(size + 1, 0);
    }
    void update(int i, int delta) {
        for (; i <= size; i += i & -i)
            tree[i] += delta;
    }
    void range(int l , int r , int delta) {
        update(l , delta);
        update(r + 1 , -delta);
        update(l , delta*(l-1));
        update(r+1 , -delta*r);
    }
    int query(int i) {
        int res = 0;
        for (; i > 0; i -= i & -i)
            res += tree[i];
        return res;
    }
    int query(int l, int r) {
        l--;
        int sum = 0;
        for (; r > l; r -= r & -r)
            sum += tree[r];
        for (; l > r; l -= l & -l)
            sum -= tree[l];
        return sum;
    }
};
