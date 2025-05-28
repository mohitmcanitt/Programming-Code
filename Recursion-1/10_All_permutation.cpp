vector<vector<int>> ans;
    void helper(vector<int>& nums, vector<bool>& used, vector<int>& temp_ans) {
        if (temp_ans.size() == nums.size()) {
            ans.push_back(temp_ans);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i])
                continue;
            used[i] = true;
            temp_ans.push_back(nums[i]);
            helper(nums, used, temp_ans);
            temp_ans.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        vector<int> temp_ans;
        helper(nums, used, temp_ans);
        return ans;
    }
