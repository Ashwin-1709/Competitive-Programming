vector<bool> is_prime;
vector<int>prime;
void prime_sieve(int MAX_PR) {
    is_prime.assign(MAX_PR + 1, 1);
    is_prime[0] = is_prime[1] = 0;
    for (int i = 4; i <= MAX_PR; i += 2)
        is_prime[i] = 0;
    for (int i = 3; i * i <= MAX_PR; i += 2)
        if (is_prime[i])
            for (int j = i * i; j <= MAX_PR; j += i * 2)
                is_prime[j] = 0;
    prime.push_back(2);
    for (int i = 3; i <= MAX_PR; i += 2) {
        if (is_prime[i])
            prime.push_back(i);
    }
}