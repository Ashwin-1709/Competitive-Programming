constexpr uint64_t mod = (1ULL << 61)  - 1;
const uint64_t seed = chrono::system_clock::now().time_since_epoch().count();
const uint64_t base = mt19937_64(seed)() % (mod / 3) + (mod / 3);

const int N = 1e5 + 10;

uint64_t binpow[N];

int64_t mul(uint64_t a , uint64_t b) {
    uint64_t l1 = (uint32_t)a, h1 = a >> 32, l2 = (uint32_t)b, h2 = b >> 32;
    uint64_t l = l1 * l2, m = l1 * h2 + l2 * h1, h = h1 * h2;
    uint64_t ret = (l & mod) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
    ret = (ret & mod) + (ret >> 61);
    ret = (ret & mod) + (ret >> 61);
    return ret - 1;
}
void calc() {
    binpow[0] = 1;
    for(int i = 1 ; i <= N - 1 ; i++)
        binpow[i] = mul(binpow[i - 1] , base);
}
struct StringHasher {
    vector<int64_t> pre , suf;
    StringHasher(string s) {
        if(!binpow[0]) calc();
        int n = s.length();
        pre.resize(n + 3);
        suf.resize(n + 3);

        for(int i = 1 ; i <= n ; i++)
            pre[i] = (mul(pre[i - 1] , base) + s[i - 1] + 997) % mod;
        for(int i = n ; i >= 1 ; i--)
            suf[i] = (mul(suf[i + 1] , base) + s[i - 1] + 997) % mod;
    }
    // 0 based indexing and [l,r]
    uint64_t fwd_hash(int l , int r) {
        int64_t hsh_val =  (pre[r + 1] - mul(binpow[r - l + 1], pre[l]) + mod) % mod;
        return hsh_val % mod;
    }

    uint64_t rev_hash(int l , int r) {
        int64_t hsh_val = (suf[l + 1] - mul(binpow[r - l + 1], suf[r + 2]) + mod) % mod;
        return hsh_val % mod;
    }

    bool isPal(int l , int r) {
        return fwd_hash(l , r) == rev_hash(l , r);
    }
};
