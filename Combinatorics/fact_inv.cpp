int modexp(int n, int M, int m = MOD) {
    int retval = 1;
    while(M > 0) {
        if(M & 1) {
            retval = (retval * n) % m;
        }
        M = M >> 1;
        n = (n * n) % m;
    }
    return retval % m;
}
int mod_inv(int x , int mod = MOD) {
    return modexp(x , mod - 2 , mod);
}
vector<int>fact,inv_fact;
void calc_fact(int MAX_FACT) {
    fact.resize(MAX_FACT + 1);
    inv_fact.resize(MAX_FACT + 1);
    fact[0] = 1;
    for(int i = 1 ; i <= MAX_FACT ; i++) {
        fact[i] = (fact[i-1] * i) % MOD;
    }
    inv_fact[MAX_FACT] = mod_inv(fact[MAX_FACT]);
    for(int i = MAX_FACT - 1 ; i >= 0 ; i--) {
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD; 
    }
}
const int M = 1e9 + 7;
int nPr(int n , int r) {
    int i = n-r+1 , p = 1;
    while(i<=n) {
        p = (p*i)%M;
        i++;
    }
    return p;
}
