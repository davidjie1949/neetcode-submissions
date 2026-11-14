class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        vec.push_back(val);
    }
    
    void pop() {
        vec.pop_back();
    }
    
    int top() {
        return vec.back();
    }
    
    int getMin() {
        return *min_element(vec.begin(), vec.end());
    }

private:
   std::vector<int> vec;
};
