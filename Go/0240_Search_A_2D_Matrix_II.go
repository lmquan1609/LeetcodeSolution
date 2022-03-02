func search(nums []int, target int) int {
	lhs, rhs := 0, len(nums)
	for lhs < rhs {
		mid := (lhs + rhs) / 2
		if nums[mid] >= target {
			rhs = mid
		} else {
			lhs = mid + 1
		}
	}
	return lhs
}

func searchMatrix(matrix [][]int, target int) bool {
    for _, row := range matrix {
		idx := search(row, target)
		if idx < len(row) && row[idx] == target {
			return true
		}
	}
	return false
}
