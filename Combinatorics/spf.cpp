vector<int>spf;
void prime_sieve(int MAX_PR) {
    spf.assign(MAX_PR + 1 , 0);
    iota(all(spf) , 0LL);
    for(int i = 2 ; i <= MAX_PR ; i+= 2) spf[i] = 2;
    for(int i = 3 ; i * i <= MAX_PR ; i++) {
        if(spf[i] == i) {
            for(int j = i * i ; j <= MAX_PR ; j+=i) {
                if(spf[j] == j) spf[j] = i;
            }
        }
    }
}
