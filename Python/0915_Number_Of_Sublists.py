from collections import Counter
class Solution:
    def solve(self, nums, target):
        right = contains = matches = 0
        target_set = set(target)
        counter = Counter()
        N = len(nums)
        MOD = 10**9 + 7

        if not target:
            return 0

        # [1, 2, 3, 4, 2, 1]
        # [1, 2, #, 2, 1, 0]
        # 

        for left in range(N):
            while right < N and matches < len(target):
                if nums[right] in target_set:
                    matches += (counter[nums[right]] == 0)
                    counter[nums[right]] += 1
                
                if matches == len(target):
                    break
                right += 1

            if matches == len(target):
                contains += N - right

            if nums[left] in target_set:
                counter[nums[left]] -= 1
                matches -= (counter[nums[left]] == 0)
                if matches < len(target):
                    right += 1

        return ((N * (N + 1) >> 1) - contains) % MOD
