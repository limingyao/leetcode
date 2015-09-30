// Ugly Number

class Solution {
public:
    bool isUgly(int num) {
        if(num<1){
            return false;
        }
        int x = num;
        while(x%2==0){
            x/=2;
        }
        while(x%3==0){
            x/=3;
        }
        while(x%5==0){
            x/=5;
        }
        return x==1?true:false;
    }
};
