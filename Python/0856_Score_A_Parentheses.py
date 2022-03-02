class Solution:
    def scoreOfParentheses(self, S: str) -> int:
        stack = []
    
        for char in S:
            if char == '(':
                stack.append(char)
            else:
                if stack and stack[-1] == '(':
                    stack.pop()
                    stack.append(1)
                else:
                    local = 0
                    while stack and stack[-1] != '(':
                        local += stack.pop()
                    stack.pop()
                    stack.append(2 * local)
        return sum(stack)
