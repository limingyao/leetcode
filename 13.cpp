// Roman to Integer

class Solution {
public:
    int romanToInt(string s) {
        int num = 0;
        if(s.size()>0){
            num += toNumber(s.at(0));
        }
        for(int i=1;i<s.size();++i){
            int front = toNumber(s.at(i-1));
            int back = toNumber(s.at(i));
            if(front<back){
                num -= 2 * front;
            }
            num += back;
        }
        return num;
    }
private:
    int toNumber(char ch) {  
        switch (ch) {  
            case 'I': return 1;  
            case 'V': return 5;  
            case 'X': return 10;  
            case 'L': return 50;  
            case 'C': return 100;  
            case 'D': return 500;  
            case 'M': return 1000;  
        }  
        return 0;  
    } 
};
