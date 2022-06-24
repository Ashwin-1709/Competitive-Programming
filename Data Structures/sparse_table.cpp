struct sparse {
    vector<int32_t>log;
    vector<vector<int32_t>>table;
    function<int(int , int)>f;
    sparse(vector<int>&a , function<int(int , int)>g) {
        f = g;
        int n = a.size();
        log.assign(n + 1 , 0);
        for(int i = 2 ; i <= n ; i++)
            log[i] = log[i/2] + 1;
        table.resize(n , vector<int32_t>(log[n] + 1));
        for(int i = 0 ; i < n ; i++)
            table[i][0] = a[i];
        for(int j = 1 ; j <= log[n] ; j++) {
            for(int i = 0 ; i + (1ll << j) <= n; i++)
               table[i][j] = f(table[i][j - 1], table[i + (1ll << (j - 1))][j - 1]);
        }
    }
    int32_t query(int l , int r) {
        if(r <= l) return 0;
        int len = log[r - l];
        return f(table[l][len] , table[r - (1LL << len)][len]);
    }
};
