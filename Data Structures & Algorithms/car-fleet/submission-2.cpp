class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> cars;
        for (int i = 0; i < n; ++i) {
            cars.push_back({position[i], (double) (target - position[i]) / speed[i]});
        }

        sort(cars.begin(), cars.end(), greater<>()); // by position, decending

        int fleets = 0;
        double lead = 0;
        for (auto& [pos, time] : cars) {
            if (time > lead) {
                ++fleets;
                lead = time;
            }
            // else: catch up, absorbed into current fleet, lead unchanged
        }
        return fleets;

        // stack<double> st; // each element = arrival time of one fleet's lead car
        // for (auto& [pos, time] : cars) {
        //     if (st.empty() || time > st.top()) {
        //         st.push(time); // can't catch fleet ahead -> new fleet
        //     }
        //     // else: time <= top, gets absorbed, don't push
        // }
        // return st.size();
    }
};
