class CountSquares {
public:
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        int x = point[0], y = point[1];
        cnt[(long)x*100001 + y]++;
        pts.push_back({x,y});
    }
    
    int count(vector<int> point) {
        int px = point[0], py = point[1], res = 0;
        for (auto& p : pts) {
            int x = p[0], y = p[1];
            if (abs(px - x) != abs(py - y) || px == x || py == y) continue;
            res += cnt[(long)x*100001 + py] * cnt[(long)px*100001 + y];
        }
        return res;
    }
private:
    unordered_map<long, int> cnt{};
    vector<array<int,2>> pts{};
};
