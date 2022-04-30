int binexp(int n, int M) {
    int retval = 1;
    while(M > 0) {
        if(M & 1) {
            retval = retval * n;
        }
        M = M >> 1;
        n = n * n;
    }
    return retval;
}