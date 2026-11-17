class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
// Brute Force Recursive Approach
        // if (amount == 0) return 0;
        // if (amount < 0) return -1;
        // int best = INT_MAX;
        // for (int c : coins) {
        //     int sub = coinChange(coins, amount - c);
        //     if (sub != -1) {
        //         best = std::min(best, sub + 1);
        //     }
        // }
        // return best == INT_MAX ? -1 : best;
// tabluation (buttom-up)
        const int INF = amount + 1;
        std::vector<int> dp(amount + 1, INF);
        dp[0] = 0;

        for (int a = 1; a <= amount; ++a) {
            for (int c : coins) {
                if (c <= a) {
                    dp[a] = std::min(dp[a], dp[a - c] + 1);
                }
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];

    }
};
