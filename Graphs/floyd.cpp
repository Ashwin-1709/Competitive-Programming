vector<vector<int>>dis(n , INT64_MAX);
//dis[u][v] -> shortest distance between u and v
auto FloydWarshall = [&]()->void { 
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            for(int k = 0 ; k < n ; k++) {
                dis[j][k] = min(dis[j][k] , dis[j][i] + dis[i][k]);
            }
        }
    }
};