const int MOD = 1e9 + 7;

long long binpow(long long x, long long n)
{
    long long ans = 1;

    while(n > 0)
    {
        if(n & 1)
            ans = (ans * x) % MOD;

        x = (x * x) % MOD;
        n >>= 1;
    }

    return ans % MOD;
}
