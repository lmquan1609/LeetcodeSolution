class LastValueMap {
    public:
    stack<int> stk;
    unordered_map<int, int> lasts;
    LastValueMap() {

    }

    void set(int key, int value) {
        stk.push(key);
        lasts[key] = value;
    }

    void remove(int key) {
        lasts.erase(key);
    }

    int getLast() {
        while (lasts.find(stk.top()) == lasts.end()) {
            stk.pop();
        }
        return lasts[stk.top()];
    }
};
