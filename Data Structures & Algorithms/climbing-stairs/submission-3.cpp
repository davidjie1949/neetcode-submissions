// Brute Force Recursion Approach
// class Solution {
// public:
//     int climbStairs(int n) {
//         if (n == 0) return 1;
//         if (n < 0) return 0;
//         return climbStairs(n-1) + climbStairs(n-2);
//     }
// };

// class Solution {
// public:
//     int climbStairs(int n) {
//         memo.assign(n+1, -1);
//         return clamp(n);
//     }

// private:
//     int clamp (int n) {
//         if (n == 0) return 1;
//         if (n < 0) return 0;
//         if (memo[n] != -1) return memo[n];
//         return memo[n] = climbStairs(n-1) + climbStairs(n-2);
//     }
//     std::vector<int> memo;
// };

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;                         // base case, same as the recursion
        for (int i = 1; i <= n; ++i)
            dp[i] = dp[i - 1] + (i >= 2 ? dp[i - 2] : 0);
        return dp[n];
    }

private:
};
