class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> res;
        string path;
        backTrack(digits, 0, path, res);
        return res;
    }
private:
    const vector<string> keys = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void backTrack(const string& digits, int k, string& path, vector<string>& res) {
        if (k == digits.size()) {
            res.push_back(path);
            return;
        }

        for (char ch : keys[digits[k] - '0']) {
            path.push_back(ch);
            backTrack(digits, k+1, path, res);
            path.pop_back();
        }
    }
};
