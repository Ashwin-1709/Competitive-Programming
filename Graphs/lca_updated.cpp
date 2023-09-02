const int LG = 18;
struct LCA {
    vector<array<int, LG>> dp;
    vector<int> tin, tout, depth;
    int n, timer;
    
    LCA(vector<vector<int>>& adj, int root = 0) : n(adj.size()) {
        dp.resize(n);
        tin.resize(n);
        tout.resize(n);
        depth.resize(n);
        timer = 0;
    
        dfs(adj, root, root);
    };
    
    void dfs(vector<vector<int>>& adj, int u, int p) {
        tin[u] = ++timer;
        dp[u][0] = p;
    
        if (u != p)
            depth[u] = depth[p] + 1;
        for (int i = 1; i < LG; ++i)
            dp[u][i] = dp[dp[u][i - 1]][i - 1];
    
        for (int i : adj[u]) {
            if (i == p) continue;
            dfs(adj, i, u);
        }
    
        tout[u] = ++timer;
    }
    
    bool is_ancestor(int u, int v) {
        return tin[u] <= tin[v] and tout[u] >= tout[v];
    }
    
    int lca(int u, int v) {
        if (is_ancestor(u, v))
            return u;
        if (is_ancestor(v, u))
            return v;
        for (int i = LG - 1; i >= 0; --i) {
            if (!is_ancestor(dp[u][i], v))
                u = dp[u][i];
        }
        return dp[u][0];
    }
};
