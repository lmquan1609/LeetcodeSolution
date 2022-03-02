func min(nums ...int) int {
	result := math.MaxInt
	for _, num := range nums {
		if result > num {
			result = num
		}
	}
	return result
}

func highestPeak(isWater [][]int) [][]int {
  rows, cols := len(isWater), len(isWater[0])
	result := make([][]int, rows)
	seen := make([][]bool, rows)
	queue := make([][]int, 0)
	for row := range isWater {
		result[row] = make([]int, cols)
		seen[row] = make([]bool, cols)
		for col := range isWater[row] {
			result[row][col] = math.MaxInt
		}
	}

	for row := 0; row < rows; row++ {
		for col := 0; col < cols; col++ {
			if isWater[row][col] == 1 {
				result[row][col] = 0
				seen[row][col] = true
				queue = append(queue, []int{row, col})
			}
		}
	}
	dirs := [][]int{
		{0, 1},
		{0, -1},
		{1, 0},
		{-1, 0},
	}

	canMove := func(nxtRow, nxtCol int) bool {
		return 0 <= nxtRow && nxtRow < rows && 0 <= nxtCol && nxtCol < cols
	}

	for len(queue) != 0 {
		sz := len(queue)

		for i := 0; i < sz; i++ {
			row, col := queue[0][0], queue[0][1]
			queue = queue[1:]

			for _, dir := range dirs {
				nxtRow, nxtCol := row+dir[0], col+dir[1]

				if canMove(nxtRow, nxtCol) && !seen[nxtRow][nxtCol] {
					seen[nxtRow][nxtCol] = true
					result[nxtRow][nxtCol] = min(
						result[nxtRow][nxtCol],
						1+result[row][col],
					)
					queue = append(queue, []int{nxtRow, nxtCol})
				}
			}
		}
	}
	return result
}
