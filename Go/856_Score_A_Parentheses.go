func scoreOfParentheses(s string) int {
  stack := make([]int, 0)

	for _, char := range s {
		if char == '(' {
			stack = append(stack, -1)
		} else {
			if len(stack) != 0 && stack[len(stack)-1] == -1 {
				stack = stack[:len(stack)-1]
				stack = append(stack, 1)
			} else {
				local := 0
				for len(stack) != 0 && stack[len(stack)-1] != -1 {
					local += stack[len(stack)-1]
					stack = stack[:len(stack)-1]
				}
				stack = stack[:len(stack)-1]
				stack = append(stack, 2*local)
			}
		}
	}
	result := 0
	for _, total := range stack {
		result += total
	}
	return result
}
