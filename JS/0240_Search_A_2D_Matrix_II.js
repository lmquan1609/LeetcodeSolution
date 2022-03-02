var search = function(nums, target){
  let lhs = 0, rhs = nums.length
  while (lhs < rhs){
    let mid = Math.floor((lhs + rhs) / 2)
    if (nums[mid] >= target){
      rhs = mid
    }else{
      lhs = mid + 1
    }
  }
  return lhs
}

var searchMatrix = function(matrix, target) {
  for (let row of matrix){
    idx = search(row, target)
    if (idx < row.length && row[idx] == target){
      return true
    }
  }
  return false
};
