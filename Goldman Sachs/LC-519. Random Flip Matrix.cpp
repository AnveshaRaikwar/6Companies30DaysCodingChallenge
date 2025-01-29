class Solution {
public:
    std::unordered_map<int, int> map;
    int zeros;
    int n, m;
    Solution(int m, int n) {
        map.clear();
        zeros = m * n;
        this->n = n;
        this->m = m;
        srand(time(0));
    }
    
    vector<int> flip() {
        int r = std::rand() % zeros;
        int actual = map.count(r) ? map[r] : r;
        std::vector<int> ret = {actual / n, actual % n};
        map[r] = map.count(zeros - 1) ? map[zeros - 1] : (zeros - 1);
        zeros--;
        return ret;
    }
    
    void reset() {
        map.clear();
        zeros = m * n;
    }
};
