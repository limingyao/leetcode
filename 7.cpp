// Reverse Integer

class Solution {
public:
    int reverse(int x) {
        int flag = x<0?-1:1;
        x = x<0?-x:x;
        int ret = 0;
        while(x!=0){
            ret = ret*10 + x%10;
            x/=10;
        }
        //添加了溢出判断
        if(flag*ret<INT_MIN||flag*ret>INT_MAX){
            return 0;
        }
        return flag*ret;
    }
};
