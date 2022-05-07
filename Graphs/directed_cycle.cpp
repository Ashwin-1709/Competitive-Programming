vector<int>visited(n+1,0) , recStack(n+1,0);
auto isCycle = [&](auto&f , int u)->bool {
    if (recStack[u]) return true;
    if (visited[u]) return false;
    visited[u] = 1;
    recStack[u] = 1;
    for(auto x : adj[u]) {
        if(f(f,x)) return true;
    }
    recStack[u] = 0;
    return false;
};
int cycles = 0;
for(int i = 1 ; i <= n ; i++) {
    if(!visited[i] and isCycle(isCycle,i)) cycles++;
}
