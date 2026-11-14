class Solution {
public:
    bool isPalindrome(string s) {
        string temp;
        for (char& c : s) {
            if (std::isalpha(c)) {
                temp += std::tolower(c);
            } else if (c >= '0' && c <= '9') {
                temp += c;
            }
        }
    
        int left = 0;
        int right = temp.size() - 1;

        while (left < right) {
            if (temp[left] != temp[right]) {
                return false;
            }
            right--;
            left++;
        }
        return true;
    }
};
