// Power of Two

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & ( n - 1)) == 0 ? true : false;
    }
};
