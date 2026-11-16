// Brute Force Recursion Approach, top->down
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

// Tabluation Method Approach Buttom->Up
// class Solution {
// public:
//     int climbStairs(int n) {
//         vector<int> dp(n + 1);
//         dp[1] = 1;
//         dp[0] = 1;                         // base case, same as the recursion
//         for (int i = 2; i <= n; ++i)
//             dp[i] = dp[i - 1] + dp[i - 2];
//         return dp[n];
//     }

// private:
// };

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        int prev2 = 1, prev1 = 2;
        for (int i = 3; i <= n; ++i) {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
