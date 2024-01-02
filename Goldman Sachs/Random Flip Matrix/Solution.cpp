class Solution {
public:
    set<pair<int,int>> s;
    int m,n;
    int cnt=0;
//   We will maintain a set storing all the numbers of matrix that are 1. While flipping we will check if the random no. is not part of this set
    Solution(int m1, int n1) {
        m = m1;
        n = n1;
    }
    
    vector<int> flip() {
        int r = rand() % m;
        int c = rand() % n;
        while(s.find({r,c}) != s.end()){
            r = rand() % m;
            c = rand() % n;
        }
        s.insert({r,c});
        vector<int> pos;
        return {r,c};
    }
    
    void reset() {
        s.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
