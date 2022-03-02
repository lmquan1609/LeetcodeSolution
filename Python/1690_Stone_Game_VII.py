class Solution:
    def stoneGameVII(self, stones: List[int]) -> int:
        pref_sum = list(accumulate(stones, initial=0))
        N = len(stones)
        
        def score(left, right):
            return pref_sum[right + 1] - pref_sum[left]
        
        @lru_cache(2000)
        def dp(left, right):
            if left == right:
                return 0
            
            return max(score(left + 1, right) - dp(left + 1, right),
											score(left, right - 1) - dp(left, right - 1))
        return dp(0, N - 1)
