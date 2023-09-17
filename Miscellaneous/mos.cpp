inline int64_t gilbertOrder(int x, int y, int pow, int rotate) {
  if (pow == 0) {
    return 0;
  }
  int hpow = 1 << (pow-1);
  int seg = (x < hpow) ? (
  (y < hpow) ? 0 : 3) : (
  (y < hpow) ? 1 : 2);
  seg = (seg + rotate) & 3;
  const int rotateDelta[4] = {3, 0, 0, 1};
  int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
  int nrot = (rotate + rotateDelta[seg]) & 3;
  int64_t subSquareSize = int64_t(1) << (2*pow - 2);
  int64_t ans = seg * subSquareSize;
  int64_t add = gilbertOrder(nx, ny, pow-1, nrot);
  ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
  return ans;
}

const int blk = 400;
struct query {
  int l , r , id;
  int64_t ord;

    bool operator<(query b) const {
      return this->ord < b.ord;
    }

  inline void calcOrder() {
    ord = gilbertOrder(l, r, 21, 0);
  }
};

// Without GilberOrder
bool operator<(query b) const {
  if (l / blk != b.l / blk)
      return  make_pair(l / blk, r) < make_pair(b.l / blk, b.r);
  return (l / blk & 1) ? (r < b.r) : (r > b.r); 
}