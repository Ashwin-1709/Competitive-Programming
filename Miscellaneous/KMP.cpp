#define sz(x) (int)x.size()

vector<array<int, 2>> KMP(vector<int>&pat, vector<int>&a) {
  int n = sz(a), m = sz(pat);
  vector<int>lps(m + 1);
  lps[0] = 0;
  int cur_len = 0, i = 1, j = 0;
  while(i < m) {
    if(pat[i] == pat[cur_len]) {
      cur_len++;
      lps[i] = cur_len;
      i++;
    } else {
      if(cur_len != 0) 
        cur_len = lps[cur_len - 1];
      else {
        lps[i] = 0;
        i++;
      }
    }
  }

  vector<array<int, 2>>matches;
  i = 0;
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