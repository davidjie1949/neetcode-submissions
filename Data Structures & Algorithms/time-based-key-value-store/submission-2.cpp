class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        list[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        auto it = list.find(key);

        string res = "";
        if (it != list.end()) {
            std::vector<std::pair<int, string>> temp = it->second;

            int left = 0;
            int right = temp.size() - 1;
            while (left <= right) {
                int mid = (left + right) / 2;

                if (timestamp >= temp[mid].first) {
                    res = temp[mid].second; // candidate, maybe a better one existsd to the right
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return res;
    }
private:
    std::unordered_map<string, std::vector<std::pair<int, string>>> list;
};
