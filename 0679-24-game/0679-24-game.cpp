class Solution {
public:
    bool solve(vector<double>& nums) {
        if (nums.size() == 1) {
            return abs(nums[0] - 24.0) < 1e-6;
        }

        // Try all pairs of numbers
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i == j) continue;

                vector<double> next;
                // Add unused numbers
                for (int k = 0; k < nums.size(); k++) {
                    if (k != i && k != j) next.push_back(nums[k]);
                }

                // Try all operations
                for (int op = 0; op < 4; op++) {
                    if (op == 0) next.push_back(nums[i] + nums[j]);
                    if (op == 1) next.push_back(nums[i] - nums[j]);
                    if (op == 2) next.push_back(nums[i] * nums[j]);
                    if (op == 3 && nums[j] != 0) next.push_back(nums[i] / nums[j]);
                    else if (op == 3) continue;

                    if (solve(next)) return true;
                    next.pop_back();  // backtrack
                }
            }
        }

        return false;
    }

    bool judgePoint24(vector<int>& cards) {
        vector<double> nums(cards.begin(), cards.end());
        return solve(nums);
    }
};
