// Max weight in the path using binary lifting (LCA)
#define LOG 20
vector<vector<int>>maxweight;
vector<vector<int>>sparse;
vector<int>depth;
vector<vector<pair<int,int>>>edge;
int n;
//initialise maxweight
function<void(int , int , int)> dfs = [&](int u , int p , int d) {
    sparse[0][u] = p;
    depth[u] = d;
    for(auto x : edge[u]) {
        if(x.first == p) continue;
        maxweight[0][x.first] = x.second;
        dfs(x.first,u,d+1);
    }
};
// build maxweight binary lifting
auto lift = [&]()->void {
    for(int i = 1 ; i < LOG ; i++) {
        for(int j = 0 ; j < n ; j++) {
            sparse[i][j] = sparse[i-1][sparse[i-1][j]];
            maxweight[i][j] = max(maxweight[i-1][j] , maxweight[i-1][sparse[i-1][j]]);
        }
    }
};
// maxweight from path u to lca and v to lca
function<int(int , int)> getmax = [&](int u , int v) {
    if(depth[v] < depth[u]) swap(u,v);
    int ans = 0 , diff = depth[v] -  depth[u];
    while (diff > 0) {
        int log = log2(diff);
        ans = max(ans, maxweight[log][v]);
        v = sparse[log][v];
        diff -= (1 << log);
    }
    while (u != v) {
        int i = log2(depth[u]);
        while (i > 0 && sparse[i][u] == sparse[i][v]) i--;
        ans = max(ans, maxweight[i][u]);
        ans = max(ans, maxweight[i][v]);
        u = sparse[i][u];
        v = sparse[i][v];
    }
    return ans;    
};
