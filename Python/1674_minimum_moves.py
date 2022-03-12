class Solution:
    def minMoves(self, nums: List[int], limit: int) -> int:
        events = [0] * (2 * limit + 2)
        
        pairs = []
        for i in range(len(nums) >> 1):
            x, y = nums[i], nums[~i]
            if x > y:
                x, y = y, x
            pairs.append((x, y))
            
        for x, y in pairs:
            # Add 2 to everything
            events[0] += 2
            events[-1] -= 2

            # Add 1 to events[x + 1 .. y + limit]
            events[x + 1] -= 1
            events[y + limit + 1] += 1
            
            # Subtract 1 from events[x + y]
            events[x + y] -= 1
            
            # Add 1 from events[x + y + 1]
            events[x + y + 1] += 1
        
        for i in range(1, len(events)):
            events[i] += events[i - 1]
            
        return min(events[:-1])
