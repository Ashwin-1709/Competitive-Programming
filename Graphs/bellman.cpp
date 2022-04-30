struct edge {
    int a , b , cost;
};

int n , m  ,v;
const int INF = 1e15;
vector<edge>e;

void bellman_ford() {
    dis[v] = 0;
    for(int i = 0 ; i < n-1 ; i++)
        for(int j = 0 ; j < m ; j++)
            if(dis[e[j].a] < INF)
                dis[e[j].b] = min(dis[e[j].b] , dis[e[j].a] + e[j].cost);
}

// we can detect negative cycle from bellman ford in 2*v*e iterations
const int NINF = (-1)*INF;
void bellman(int n , int m , int v) {
    dis[v] = 0;
    for(int i = 1 ; i < n ; i++) {
        for(auto y : e) {
            if(dis[y.a] == INF) continue;
            dis[y.b] = min(dis[y.b], y.cost + dis[y.a]);
            dis[y.b] = max(dis[y.b] , NINF);
        }
    }
    for(int i = 1 ; i < n ; i++) {
        for(auto y : e) {
            if(dis[y.a] == INF) continue;
            dis[y.b] = max(dis[y.b] , NINF);
            if(dis[y.a] + y.cost < dis[y.b]) {
                dis[y.b] = NINF;
            }
        }
    }
}