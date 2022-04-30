vector<vector<pair<int,int>>>adj;
vector<int>dis(n,INT64_MAX),par;
auto dijkstra = [&](int root) -> void{
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>>p;
    dis[root] = 0;
    p.push({0,root});
    while(!p.empty()) {
        auto c = p.top(); p.pop();
        int curr_node = c.second ,curr_dis = c.first;
        if(curr_dis != dis[curr_node] ) continue; 
        for(auto x : adj[curr_node]) {
          if(curr_dis + x.second < dis[x.first]) {
            dis[x.first] = curr_dis + x.second;
            p.push({dis[x.first],x.first});
          }
        }
    }
};
vector<int>restore_path(int u , int v , vector<int>&par) {
    vector<int>path;
    for(int i = v ; i != u ; i = par[i]) {
        path.push_back(i);
    }
    path.push_back(u);
    reverse(all(path));
    return path;
}