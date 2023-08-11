template<int N = 1>
vector<bool> fast_knapsack(vector<int>&weights, int total_wt) {
  if(total_wt > N)
    return fast_knapsack<min(2 * N, INF)>(weights, total_wt);

  vector<bool>knapsack(total_wt + 1, false);
  knapsack[0] = true;
  
  if(sz(weights) <= 1) {
    knapsack[weights.front()] = true;
    return knapsack;
  }
  
  map<int, int>compress;
  for(auto &wt : weights)
    compress[wt]++;
  
  bitset<N>dp;
  dp.set(0, true);
  for(auto &[wt, freq] : compress) {
    while(freq > 2) {
      compress[2 * wt]++;
      freq -= 2;
    }

    while(freq--)
      dp |= (dp << wt);
  }

  for(int i = 0; i <= total_wt; i++)
    knapsack[i] = dp[i];
  return knapsack;
}
