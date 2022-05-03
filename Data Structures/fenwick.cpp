template<typename T>
struct fenwick_tree {
    vector<T> BIT;
    int n;
    fenwick_tree(int n) {
        this->n = n;
        BIT.assign(n,0);
    }
    void update(int i, T add) {
        while (i < n) {
            BIT[i] += add;
            i |= (i + 1);
        }
    }
    T sum(int i) {
        T ans{};
        while (i >= 0) {
            ans += BIT[i];
            i = (i & (i + 1)) - 1;
        }
        return ans;
    }
    T sum(int l , int r) {
        return sum(r) - sum(l-1);
    }
    void update(int l , int r , int delta) {
        update(l , delta);
        update(r + 1 , -delta); 
    }
};