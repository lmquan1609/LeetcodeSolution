const int MOD = 1000000007;
int solve(vector<int>& nums, vector<int>& target) {
    if (target.size() == 0) return 0;
    int rhs = 0, contains = 0;
    int N = nums.size();
    long long result = N * (N + 1LL) / 2;
    unordered_map<int, int> counter;
    unordered_set<int> interesting(target.begin(), target.end());

    int lhs = 0;
    for (int rhs = 0; rhs < N; rhs++) {
        if (interesting.count(nums[rhs])) counter[nums[rhs]]++;
        while (counter.size() == interesting.size()) {
            contains += N - rhs;
            if (interesting.count(nums[lhs])) {
                if (--counter[nums[lhs]] == 0) counter.erase(nums[lhs]);
            }
            lhs++;
        }
    }
    return (result - contains) % MOD;
}
