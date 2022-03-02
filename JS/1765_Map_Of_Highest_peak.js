var highestPeak = function(isWater) {
  const rows = isWater.length, cols = isWater[0].length

  const queue = []
  const seen = new Map()
  const result = Array(rows).fill(Infinity).map(() => Array(cols).fill(Infinity))

  convertToKey = function (...args){
    return args.join('|')
  }

  for (let row = 0; row < rows; row++){
    for (let col = 0; col < cols; col++){
      if (isWater[row][col]){
        queue.push([row, col])
        result[row][col] = 0
        seen.set(convertToKey(row, col), true)
      }
    }
  }

  const dirs = [[0, -1], [0, 1], [-1, 0], [1, 0]]
  getNei = function(row, col){
    return dirs.map(([rowStep, colStep]) => [row + rowStep, col + colStep])
                .filter(([neiRow, neiCol]) => 0 <= neiRow && neiRow < rows && 0 <= neiCol && neiCol < cols)
  }
  
  while (queue.length > 0){
    [row, col] = queue.shift()
    const neiCoords = getNei(row, col)
    neiCoords.filter(([neiRow, neiCol]) => !seen.has(convertToKey(neiRow, neiCol)))
              .forEach(([neiRow, neiCol]) => {
                seen.set(convertToKey(neiRow, neiCol), true)
                result[neiRow][neiCol] = Math.min(
                  result[neiRow][neiCol], 1 + result[row][col]
                )
                queue.push([neiRow, neiCol])
              })
  }
  return result
}
