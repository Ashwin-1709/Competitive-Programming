struct DSU {
  vector<int> parent,sze;
  void build(int n , bool init) {
    parent.resize(n,0) , sze.resize(n,-1);
    for(int k = 0 ; k < n ; k++) parent[k] = k , sze[k] = 1;
  }
  int find(int v) {
    if(parent[v] == v) return v;
    else return parent[v] = find(parent[v]);
  }
  void unite(int a , int b) {
    a = find(a) , b = find(b);
    if(a != b) {
      if(sze[a] < sze[b]) swap(a,b);
      parent[b] = a , sze[a] += sze[b];
    }
  }
} dsu;