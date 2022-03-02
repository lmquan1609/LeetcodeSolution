#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target){
        int lhs = 0, rhs = nums.size();
        while (lhs < rhs) {
            int mid = lhs + rhs >> 1;
            if (nums[mid] >= target) {
                rhs = mid;
            } else {
                lhs = mid + 1;
            }
        }
        
        return lhs;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();
        for (auto& row : matrix) {
            int idx = search(row, target);
            if (idx < cols && row[idx] == target) {
                return true;
            }
        }
        return false;
    }
};
