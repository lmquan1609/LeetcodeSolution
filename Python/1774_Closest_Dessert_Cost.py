class Solution:
    result = float('inf')
    def closestCost(self, baseCosts: List[int], toppingCosts: List[int], target: int) -> int:
        N, M = len(baseCosts), len(toppingCosts)
        def dfs(idx, cost):
            if idx < M:
                dfs(idx + 1, cost)
                dfs(idx + 1, cost + toppingCosts[idx])
                dfs(idx + 1, cost + 2 * toppingCosts[idx])
            else:
                for base in baseCosts:
                    check(base + cost)
        
        def check(total):
            if abs(total - target) < abs(self.result - target):
                self.result = total
            elif abs(total - target) == abs(self.result - target) and total < self.result:
                self.result = total
        
        dfs(0, 0)
        return self.result
