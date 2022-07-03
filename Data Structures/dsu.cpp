struct DSU {
    vector<int>par , sze;
    void build(int n , bool init) {
        par.resize(n);
        iota(all(par) , 0LL);
        sze.resize(n , 1);
    }
    int find(int v) {
        if(par[v] == v) return v;
        return par[v] = find(par[v]);
    }
    void unite(int u , int v) {
        u = find(u) , v = find(v);
        if(u != v) {
            if(sze[u] < sze[v]) swap(u , v);
            sze[u] += sze[v];
            par[v] = u;
        }
    }
}dsu;
