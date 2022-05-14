<<<<<<< HEAD
<<<<<<< HEAD
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
=======
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
>>>>>>> fd0406fa317c6de3a3306f0798b9d2739a64faa9
};
=======
// 0 based indexing
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
>>>>>>> 361f51a5d312c329b368072612741a5256323f5e
