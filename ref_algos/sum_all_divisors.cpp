void sum_all_divisors(int n, vector<long long>& sigma)
{
	sigma.assign(n+1, 1);

    for(int i = 2; i <= n; i++)
        for(int j = i; j <= n; j += i)
            sigma[j] += i;
}