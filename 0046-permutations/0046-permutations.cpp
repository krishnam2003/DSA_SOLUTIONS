class Solution {
public:
    void backtrack(vector<int>& nums, vector<int>& curr,
                   vector<bool>& used, vector<vector<int>>& ans) {

        // Base case
        if (curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
                                               // Skip already used elements
            if (used[i]){
                continue;
            };

            // Choose
            curr.push_back(nums[i]);
            used[i] = true;

            // Explore
            backtrack(nums, curr, used, ans);

            // Undo (Backtrack)
            curr.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        vector<bool> used(nums.size(), false);

        backtrack(nums, curr, used, ans);

        return ans;
    }
};