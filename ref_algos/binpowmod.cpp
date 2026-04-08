long long binpow(long long a, long long n, long long m) {
    long long ans = 1;
    while (n > 0) {
        if (n & 1)
            ans = ans * a % m;
        a = a * a % m;
        n >>= 1;
    }
    return ans;
}
