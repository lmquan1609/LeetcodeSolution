function canChoose(groups, nums){
  let j = 0, M = nums.length

  for (let grp of groups){
    let N = grp.length
    let i = 0, pastJ = j

    while (i < N && j < M){
      if (grp[i] == nums[j]){
        i += 1
      } else {
        i = 0
        j = pastJ
        pastJ += 1
      }
      j += 1
    }
    if (i < N){
      return false
    }
  }
  return true
}
