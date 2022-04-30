struct sparse {
    typedef int32_t item;
    vector<int32_t> log;
    vector<vector<item>> table;
    function<int(int, int)> op;

    void init(int n, vector<int>& a) {
        log.assign(n + 1, 0);
        for (int i = 2; i <= n; ++i)
            log[i] = log[i / 2] + 1;
        table = vector<vector<item>>(n, vector<item>(log[n] + 1));
        for (int i = 0; i < n; ++i)
            table[i][0] = a[i];
        for (int j = 1; j <= log[n]; ++j)
            for (int i = 0; i + (1ll << j) <= n; ++i)
                table[i][j] = op(table[i][j - 1], table[i + (1ll << (j - 1))][j - 1]);
    }

    sparse(vector<int>& a, function<int(int, int)> f) {
        op = f;
        init(a.size(), a);
    }
    item query(int l, int r) {
        if (r <= l)
            return 0;
        int j = log[r - l];
        return op(table[l][j], table[r - (1ll << j)][j]);
    }
};