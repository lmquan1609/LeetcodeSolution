class Solution:
    def getCollisionTimes(self, cars: List[List[int]]) -> List[float]:
        N = len(cars)
        dists, vels = zip(*cars)
        result = [-1] * N
        stack = []
        
        def collision_time(i, j):
            diff_dist = dists[i] - dists[j]
            diff_vel = vels[j] - vels[i]
            return diff_dist / diff_vel if diff_vel else float('inf')
        
        for i in range(N -1, -1, -1):
            while (
                stack and vels[i] <= vels[stack[-1]] or 
                len(stack) >= 2 and collision_time(i, stack[-1]) > collision_time(stack[-1], stack[-2])
            ):
                stack.pop()
        
            if stack:
                result[i] = collision_time(i, stack[-1])
            stack.append(i)
        return result
