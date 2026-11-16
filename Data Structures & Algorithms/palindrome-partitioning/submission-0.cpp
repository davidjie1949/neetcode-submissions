class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        backTrack(s, 0, path, res);
        return res;
    }

private:
    void backTrack(const string& s, int start, vector<string>& path, vector<vector<string>>& res) {
        if (start == s.size()) {                // the whole string is consumed
            res.push_back(path);
            return;
        }

        for (int i = start; i < s.size(); ++i) {
            if (!isPal(s, start, i)) continue;  // prune: the piece must be a palindrome
            path.push_back(s.substr(start, i - start + 1)); // choose s[start..i]
            backTrack(s, i + 1, path, res);                 // continue after the cut
            path.pop_back();                                // un-choose
        }
    }

    bool isPal(const string& s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }

        return true;
    }
};
