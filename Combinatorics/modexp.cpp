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