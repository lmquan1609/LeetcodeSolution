class Solution:
    def canChoose(self, groups: List[List[int]], nums: List[int]) -> bool:
        j = 0
        M = len(nums)
        
        for grp in groups:
            N = len(grp)
            i = 0
            past_j = j
            while i < N and j < M:
                if grp[i] == nums[j]:
                    i += 1
                else:
                    i = 0
                    j = past_j
                    past_j += 1
                j += 1
            
            if i < N:
                return False
        return True
