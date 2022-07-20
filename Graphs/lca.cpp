vector<vector<int>>adj(n) , sparse(n , vector<int>(25));
vector<int>depth(n);
auto f = [&](auto &&f , int u , int p) -> void{
    for(auto v : adj[u]) {
        if(v == p) continue;
        depth[v] = depth[u] + 1;
        sparse[v][0] = u;
        for(int i = 1 ; i < 25 ; i++) {
            sparse[v][i] = sparse[sparse[v][i - 1]][i - 1];
        }
        f(f , v , u);
    }
};

auto lca = [&](int a , int b) -> int {
    if(depth[a] < depth[b]) swap(a , b);
    int k = depth[a] - depth[b];
    for(int i = 24 ; i >= 0 ; i--) {
        if((1 << i) & k) a = sparse[a][i];
    }
    if(a == b) return a;
    for(int i = 24 ; i >= 0 ; i--) {
        if(sparse[a][i] != sparse[b][i]) {
            a = sparse[a][i];
            b = sparse[b][i];
        }
    }
    return sparse[a][0];
};
