class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string path;
        backTrack(n, 0, 0, path, res);
        return res;
    }

private:
    void backTrack(int n, int open, int close, string& path, vector<string>& res) {
        if (path.size() == 2*n) {
            res.push_back(path);
            return;
        }

        if (open < n) {
            path.push_back('(');
            backTrack(n, open + 1, close, path, res);
            path.pop_back();
        }
        if (close < open) {
            path.push_back(')');
            backTrack(n, open, close + 1, path, res);
            path.pop_back();
        }
    }
};
