// INF is bound for total weight sum
// weights need to be sorted before calling the function

const int INF = 1e6 + 100;

template<int N = 1>
int fast_knapsack_product(vector<int>&weights, int total_wt) {
  if(total_wt > N)
    return fast_knapsack_product<min(2 * N, INF)>(weights, total_wt);

  if(sz(weights) <= 1)
    return 0;

  if(weights.back() * 2LL >= total_wt)
    return weights.back() * (total_wt - weights.back());

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
  int best = dp._Find_next(total_wt / 2 - 1);
  return best * (total_wt - best);
}