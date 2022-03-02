var stoneGameVII = function(stones) {
  const N = stones.length
  const prefSum = [0]
  stones.reduce((total, num, idx) => prefSum[idx + 1] = total + num, 0)
  const dp = new Map()
  
  score = function(lhs, rhs){
    return prefSum[rhs + 1] - prefSum[lhs]
  }

function convertToKey(...args){
    return args.join('|')
  }

  memo = function(lhs, rhs) {
    if (lhs === rhs) return 0

    let key = convertToKey(lhs, rhs)
    if (dp.has(key)) return dp.get(key)

    result = Math.max(score(lhs + 1, rhs) - memo(lhs + 1, rhs), score(lhs, rhs - 1) - memo(lhs, rhs - 1))
    dp.set(key, result)
    return result
  }
  return memo(0, N - 1)
};
