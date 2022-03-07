class Solution {
public:
    void check(int total, int target, int& result) {
        if (abs(total - target) < abs(result - target)) {
            result = total;
        } else if (abs(total - target) == abs(result - target) && total < result) {
            result = total;
        }
    }

    void dfs(vector<int>& baseCosts, vector<int>& toppingCosts, int target, int idx, int cost, int& result) {
        if (idx < toppingCosts.size()) {
            dfs(baseCosts, toppingCosts, target, idx + 1, cost, result);
            dfs(baseCosts, toppingCosts, target, idx + 1, cost + toppingCosts[idx], result);
            dfs(baseCosts, toppingCosts, target, idx + 1, cost + 2 * toppingCosts[idx], result);
        } else {
            for (auto& base : baseCosts) {
                check(base + cost, target, result);
            }
        }
    }
    
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int result = INT_MAX;
        dfs(baseCosts, toppingCosts, target, 0, 0, result);
        return result;
    }
};
