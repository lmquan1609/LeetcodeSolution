class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int j = 0, M = nums.size();

        for (auto& grp : groups) {
            int i = 0, N = grp.size();
            int prev_j = j;
            while (i < N && j < M) {
                if (grp[i] == nums[j]) {
                    i += 1;
                } else {
                    i = 0;
                    j = prev_j;
                    prev_j += 1;
                }
                j += 1;
            }
            if (i < N) {
                return false;
            }
        }
        return true;
    }
};
