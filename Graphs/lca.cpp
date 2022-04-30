vector<int>depth(n,0); 
int sparse[n][20] = {0};
function<void(int, int)> dfs = [&](int u, int p = -1) {
    for (auto v : adj[u]) {
        if (v == p)
            continue;
        depth[v] = depth[u] + 1;
        sparse[v][0] = u;
        for (int j = 1; j < LOG; j++) {
            sparse[v][j] = sparse[sparse[v][j - 1]][j - 1];
        }
        dfs(v, u);
    }
};

auto lca = [&](int u , int v) -> int {
    if (depth[u] < depth[v]) swap(u, v);
    int k = depth[u] - depth[v];
    for (int j = LOG - 1; j >= 0; j--) {
        if (1 & (k >> j)) u = sparse[u][j]; // send u up till depth of u , v is same
    }
    if (u == v) return u;
    for (int j = LOG - 1; j >= 0; j--) {
        if (sparse[u][j] != sparse[v][j]) { // send both u and v up till u = v (common ancestor)
            u = sparse[u][j]; 
            v = sparse[v][j];
        }
    }
    return sparse[u][0];
};