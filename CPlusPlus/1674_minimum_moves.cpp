class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int N = 2 * limit + 2;
        int M = nums.size();
        vector<int> events(N, 0);

        vector<pair<int, int>> pairs;
        for (int i = 0; i < nums.size() / 2; i++) {
            int x = nums[i], y = nums[M - i - 1];
            if (x > y) swap(x, y);
            pairs.push_back({x, y});
        }
        for (auto& pair : pairs) {
            int x = pair.first, y = pair.second;
            events[0] += 2;
            events[N - 1] -= 2;

            events[x + 1] -= 1;
            events[y + limit + 1] += 1;

            events[x + y] -= 1;
            events[x + y + 1] += 1;
        }
        
        for (int i = 1; i < N; i++) {
            events[i] += events[i - 1];
        }
        int result = INT_MAX;
        for (int i = 0; i < N - 1; i++){
            result = min(result, events[i]);
        }
        return result;
    }
};
