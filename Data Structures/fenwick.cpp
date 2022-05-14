template<typename T>
struct fenwick_tree {
    vector<T> BIT;
    int n;
    fenwick_tree(int n) {
        this->n = n;
        BIT.assign(n,0);
    }
    void update(int i, T add) {
        for( ; i < n ; i|=(i+1)) {
            BIT[i] += add;
        }
    }
    T sum(int i) {
        T ans{};
        for( ; i >= 0 ; i = (i & (i + 1 )) - 1) {
            ans += BIT[i];
        }
        return ans;
    }
    T sum(int l , int r) {
        return sum(r) - sum(l-1);
    }
};
