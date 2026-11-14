class Solution {
public:
    bool isHappy(int n) {
        // Floyd's cycle detection
        auto next = [](int x) {
            int sum = 0;
            while (x) {
                int d = x % 10;
                sum += d * d;
                x /= 10;
            }
            return sum;
        };

        int slow = n, fast = next(n);
        while (fast != 1 && slow != fast) {
            slow = next(slow);
            fast = next(next(fast));
        }

        return fast == 1;
    }
};
