int sieve[500005];
void pre()
{
    int n=5e5;
    sieve[0] = sieve[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (sieve[i] != 0) continue;
        for (int j = i; j <= n; j += i)
            sieve[j] = i;
    }
}