long long kadane(int n, vector<int>& nums)
{
    long long current_sum = 0, max_sum = INT_MIN;

    for(int i = 0; i  n; i++)
    {
        current_sum += nums[i];

        max_sum = max(current_sum, max_sum);

        if(current_sum  0)
            current_sum = 0;
    }

    return max_sum;
}