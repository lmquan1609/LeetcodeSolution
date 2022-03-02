class Solution:
    def highestPeak(self, isWater: List[List[int]]) -> List[List[int]]:
        rows, cols = len(isWater), len(isWater[0])
        
        def getNei(row, col):
            for nxt_col in (col - 1, col + 1):
                if 0 <= nxt_col < cols:
                    yield row, nxt_col
            
            for nxt_row in (row - 1, row + 1):
                if 0 <= nxt_row < rows:
                    yield nxt_row, col
        
        queue = []
        seen = set()
        result = [[float('inf')] * cols for _ in range(rows)]
        
        for row, col in product(range(rows), range(cols)):
            if isWater[row][col]:
                queue.append((row, col))
                result[row][col] = 0
                seen.add((row, col))
        
        for row, col in queue:
            for nei in getNei(row, col):
                if nei not in seen:
                    seen.add(nei)
                    result[nei[0]][nei[1]] = min(result[nei[0]][nei[1]],
																								result[row][col] + 1)
                    queue.append(nei)
        return result
