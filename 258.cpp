// Add Digits

class Solution {
public:
    int addDigits(int num) {
        int x = num;
        int sum = 0;
        while(true){
            sum += x % 10;
            x /= 10;
            if(x==0){
                x = sum;
                sum = 0;
                if(x/10==0){
                    break;
                }
            }
        }
        return x;
    }
};

class Solution {
public:
    int addDigits(int num) {
        if(num==0) return 0;
        return num % 9 == 0 ? 9 : num % 9;
    }
};

class Solution {
public:
    int addDigits(int num) {
        return 1 + (num - 1) % 9;
    }
};
