int score(vector<int>& array, int lhs, int rhs) {
    return array[rhs + 1] - array[lhs];
}

int memo(vector<vector<int>>& dp, vector<int>& prefSum, int lhs, int rhs) {
    if (lhs == rhs) return 0;
    if (dp[lhs][rhs] != -1) return dp[lhs][rhs];

    int result = max(
        score(prefSum, lhs + 1, rhs) - memo(dp, prefSum, lhs + 1, rhs),
        score(prefSum, lhs, rhs - 1) - memo(dp, prefSum, lhs, rhs - 1));
    return dp[lhs][rhs] = result;
}

int stoneGameVII(vector<int>& stones) {
    int N = stones.size();
    vector<int> prefSum(N + 1);
	  int count = 1;
    for (auto stone : stones) {
        prefSum[count++] += prefSum[count - 1] + stone;
    }

		// or
		// int count = 0;
    // for (auto stone : stones) {
    //     prefSum[++count] += prefSum[count] + stone;
		// }

    vector<vector<int>> dp(N, vector<int>(N, -1));
    return memo(dp, prefSum, 0, N - 1);
}
