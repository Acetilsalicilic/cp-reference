long long binpow(long long a, long long n) {
    long long ans = 1;
    while (n > 0) {
        if (n & 1)
            ans *= a;
        a *= a;
        n >>= 1;
    }
    return ans;
}
