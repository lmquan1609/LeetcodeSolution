func canChoose(groups [][]int, nums: []int) bool {
	j, M := 0, len(nums)

	for _, grp := range groups {
		N := len(grp)
		i, pastJ := 0, j

		for i < N && j < M {
			if grp[i] == nums[j] {
				i += 1
			} else {
				i, j = 0, pastJ
				pastJ += 1
			}
			j += 1
		}
		if i < N{
			return false
		}
	}
	return true;
}
