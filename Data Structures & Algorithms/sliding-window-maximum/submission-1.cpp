class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; // stores indices, values decreasing
        vector<int> res;

        for (int i = 0; i < nums.size(); ++i) {
            // pop indices that fell out of the window
            if (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();
            
            // pop smaller values from the back; they can never be max
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();

            dq.push_back(i);

            // front is the max of the current window
            if (i >= k - 1)
                res.push_back(nums[dq.front()]);
        }

        return res;
    }
};
