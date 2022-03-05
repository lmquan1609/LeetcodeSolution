class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int N = cars.size();
        vector<int> dists;
        vector<int> vels;

        for (auto& car : cars) {
            dists.push_back(car[0]);
            vels.push_back(car[1]);
        }
        vector<double> result(N, -1), stack;

        auto collisionTime = [&](int i, int j) {
            return (double)(dists[i] - dists[j]) / (vels[j] - vels[i]);
        };

        for (int i = N - 1; i >= 0; i--) {
            while (
                (!stack.empty() && vels[i] <= vels[stack.back()]) ||
                (stack.size() >= 2 && collisionTime(i, stack.back()) > result[stack.back()])) {
                stack.pop_back();
            }
            if (!stack.empty()) result[i] = collisionTime(i, stack.back());
            stack.push_back(i);
        }
        return result;
    }
};
