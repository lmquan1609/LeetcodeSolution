class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        def search(row_idx):
            left, right = 0, len(matrix[row_idx])
            while left < right:
                mid = left + right >> 1
                if matrix[row_idx][mid] >= target:
                    right = mid
                else:
                    left = mid + 1
            return left
                
        for row_idx in range(len(matrix)):
            idx = search(row_idx)
            if idx < len(matrix[row_idx]) and matrix[row_idx][idx] == target:
                return True
        return False
