#define sz(x) (int)x.size()

vector<array<int, 2>> KMP(vector<int>&pat, vector<int>&a) {
  int n = sz(a), m = sz(pat);
  vector<int>lps(m);
  for(int i = 1; i < m; i++) {
    int j = lps[i - 1];
    while(j > 0 and pat[i] != pat[j])
      j = lps[j - 1];
    if(pat[i] == pat[j])
      j++;
    lps[i] = j;
  }

  vector<array<int, 2>>matches;
  int i = 0, j = 0;
  while((n - i) >= (m - j)) {
    if(pat[j] == a[i]) 
      i++, j++;
    
    if(j == m) {
      matches.push_back({i - j, i - j + m - 1});
      j = lps[j - 1];
    } else if(i < n and pat[j] != a[i]) {
      if(j != 0)
        j = lps[j - 1];
      else i++;
    }
  }

  return matches;
}
