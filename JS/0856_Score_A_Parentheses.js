/**
 * @param {string} s
 * @return {number}
 */
var scoreOfParentheses = function(s) {
  let stack = []
  for (let char of s){
    if (char == '('){
      stack.push(char)
    } else {
      if (stack.length > 0 && stack[stack.length - 1] == '('){
        stack.pop()
        stack.push(1)
      } else {
        local = 0
        while (stack.length > 0 && stack[stack.length - 1] != '('){
          local += stack.pop()
        }
        stack.pop()
        stack.push(2 * local)
      }
    }
  }
  
  return stack.reduce((total, currVal) => {
    return total + currVal
  }, 0)
};
