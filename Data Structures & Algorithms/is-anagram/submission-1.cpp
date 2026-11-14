class Solution {
public:
    bool isAnagram(string s, string t) {
        // Brute Force
        // if (s.size() != t.size()) return false;
        // std::unordered_map<char, int> freq {0};

        // for (char c : s) freq[c - 'a']++;
        // for (char c : t) {
        //     if (--freq[c - 'a'] < 0) return false;
        // }

        // return true;

        // sorting approach
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};
