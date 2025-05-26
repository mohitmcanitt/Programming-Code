class Solution {
public:
    Solution() { map_key_(); }

    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {}; // Return empty vector for empty input
        return letterCombinationsHelper_(digits);
    }

private:
    unordered_map<string, string> key_map_;
    void map_key_() {
        key_map_["2"] = "abc";
        key_map_["3"] = "def";
        key_map_["4"] = "ghi";
        key_map_["5"] = "jkl";
        key_map_["6"] = "mno";
        key_map_["7"] = "pqrs";
        key_map_["8"] = "tuv";
        key_map_["9"] = "wxyz";
    }

    vector<string> letterCombinationsHelper_(string digits) {
        if (digits.empty())
            return {""};

        string first_digits = digits.substr(0,1);
        string remaining_digits = digits.substr(1);

        vector<string> remaining_ans =
            letterCombinationsHelper_(remaining_digits);

        vector<string> ans;

        for (const auto& ch : key_map_[first_digits]) {
            for (const auto& key : remaining_ans) {
                ans.push_back(string(1, ch) + key);
            }
        }

        return ans;
    }
};
