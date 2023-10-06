const int N = 5e5 + 10;

struct SCC {
  vector<vector<int>>adj , transpose , adj_scc , scc_decomp;
  bitset<N>used;
  vector<int>order , cmp , sze , roots;
  int scc_sze;
  int n;
  SCC(vector<vector<int>>& g) {
    this->n = g.size();
    this->adj = g;
    roots.resize(n);
    sze.resize(n);
    scc_decomp.resize(n);
    transpose.resize(n);
    scc_sze = 0;

    for(int i = 0 ; i < n ; i++) {
      for(auto x : adj[i]) 
        transpose[x].push_back(i);
    }
  }
  void topo(int u){
    used[u] = 1;
    for(auto x  : adj[u]) {
      if(!used[x]) topo(x);
    }
    order.push_back(u);
  };

  void dfs(int u) {
    used[u] = 1;
    cmp.push_back(u);
    for(auto x : transpose[u])
      if(!used[x]) dfs(x);
  };

  void build() {
    for(int i = 0 ; i < n ; i++) 
        if(!used[i]) topo(i);
    used.reset();
    reverse(begin(order), end(order));
    for(auto u : order) {
      if(!used[u]) {
        dfs(u);
        int cur_root = scc_sze++;
        for(auto x : cmp) roots[x] = cur_root;
        sze[cur_root] = cmp.size();
        swap(scc_decomp[cur_root] , cmp);
      }
    }
    adj_scc.resize(scc_sze);
    for(int i = 0 ; i < n ; i++) {
      for(auto x : adj[i]) {
        int cur_root = roots[i] , x_root = roots[x];
        if(cur_root != x_root) adj_scc[cur_root].push_back(x_root);
      }
    }
  }
};
