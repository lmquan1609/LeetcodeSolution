import (
	"fmt"
	"math"
)

func min(nums ...int) int {
	result := math.MaxInt
	for _, num := range nums {
		if result > num {
			result = num
		}
	}
	return result
}

func max(nums ...int) int {
	result := math.MinInt
	for _, num := range nums {
		if result < num {
			result = num
		}
	}
	return result
}

func stoneGameVII(stones []int) int {
  N := len(stones)

	prefSum := make([]int, N+1)
	for i := 0; i < N; i++ {
		prefSum[i+1] = prefSum[i] + stones[i]
	}

	dp := make([][]int, N)
	for i := 0; i < N; i++ {
		dp[i] = make([]int, N)
	}

	score := func(lhs, rhs int) int {
		return prefSum[rhs+1] - prefSum[lhs]
	}

	var memo func(int, int) int
	memo = func(lhs, rhs int) int {
		if lhs == rhs {
			return 0
		}
		if dp[lhs][rhs] != 0 {
			return dp[lhs][rhs]
		}
		result := max(
			score(lhs+1, rhs)-memo(lhs+1, rhs),
			score(lhs, rhs-1)-memo(lhs, rhs-1),
		)
		dp[lhs][rhs] = result
		return result
	}
	return memo(0, N-1)
}
