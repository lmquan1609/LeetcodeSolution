class Solution {
public:
    bool canMove(int nxtRow, int nxtCol, int rows, int cols) {
        return nxtRow >= 0 && nxtRow < rows && nxtCol >= 0 && nxtCol < cols;
    }
    
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int rows = isWater.size(), cols = isWater[0].size();
        vector<vector<int>> result(rows, vector<int>(cols, numeric_limits<int>::max()));
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(rows, vector<bool>(cols, 0));
        vector<pair<int, int>> dirs = {
            {-1, 0},
            {0, 1},
            {1, 0},
            {0, -1}};

        for (auto row = 0; row < rows; row++) {
            for (auto col = 0; col < cols; col++) {
                if (isWater[row][col]) {
                    result[row][col] = 0;
                    visited[row][col] = 1;
                    q.push({row, col});
                }
            }
        }

        while (!q.empty()) {
            pair<int, int> topVal = q.front();
            q.pop();
            int row = topVal.first, col = topVal.second;

            for (auto& dir : dirs) {
                int nxtRow = row + dir.first, nxtCol = col + dir.second;
                if (canMove(nxtRow, nxtCol, rows, cols) && visited[nxtRow][nxtCol] == 0) {
                    visited[nxtRow][nxtCol] = 1;
                    result[nxtRow][nxtCol] = min(result[nxtRow][nxtCol], 1 + result[row][col]);
                    q.push({nxtRow, nxtCol});
                }
            }
        }
        return result;
    }
};
