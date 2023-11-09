template<typename T>
struct fenwick_2D {
    vector<vector<T>> bit;
    int n;
    fenwick_2D(int n) {
        this->n = n;
        bit.assign(n, vector<T>(n));
    }
    void add(int i, int j, T delta) {
        for (; i < n; i = i | (i + 1))
            for (int y = j; y < n; y = y | (y + 1))
                bit[i][y] += delta;
    }
    T sum(int i, int j) {
        T val{};
        for (; i >= 0; i = (i & (i + 1)) - 1)
            for (int y = j; y >= 0; y = (y & (y + 1)) - 1)
                val += bit[i][y];
        return val;
    }
    T sum(int x1, int y1, int x2, int y2) {
        return sum(x2, y2) - sum(x2, y1 - 1) - sum(x1 - 1, y2) + sum(x1 - 1, y1 - 1);
    }
};
