class Solution {
public:
    bool isPalindrome(string s) {
        // string temp;
        // for (char& c : s) {
        //     if (std::isalnum(c)) {
        //         temp += std::tolower(c);
        //     }
        // }
    
        // int left = 0;
        // int right = temp.size() - 1;

        // while (left < right) {
        //     if (temp[left] != temp[right]) {
        //         return false;
        //     }
        //     right--;
        //     left++;
        // }
        // return true;

        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            while (left < right && !std::isalnum(static_cast<unsigned char>(s[left]))) left++;
            while (left < right && !std::isalnum(static_cast<unsigned char>(s[right]))) right--;
            if (std::tolower(static_cast<unsigned char>(s[left])) != std::tolower(static_cast<unsigned char>(s[right]))) return false;
            left++;
            right--; 
        }
        return true;
    }
};
