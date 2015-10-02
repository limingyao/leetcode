// Integer to Roman

class Solution {
    public:
        string intToRoman(int num) {
            string roman[][10] = {
                // 1 ~ 9
                {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
                // 10 ~ 90
                {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
                // 100 ~ 900
                {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
                // 1000 ~ 3000
                {"", "M", "MM", "MMM"}  
            };
            string word;
            if(num/1000!=0){
                word += roman[3][num/1000];
                num %= 1000;
            }
            if(num/100!=0){
                word += roman[2][num/100];
                num %= 100;
            }
            if(num/10!=0){
                word += roman[1][num/10];
                num %= 10;
            }
            if(num!=0){
                word += roman[0][num];
            }
            return word;
        }
};

// Method 2:
class Solution {
    public:
        string intToRoman(int num) {
            string str;  
            string symbol[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};  
            int value[]=    {1000,900,500,400, 100, 90,  50, 40,  10, 9,   5,  4,   1}; 
            for(int i=0;num!=0;++i)
            {
                while(num>=value[i])
                {
                    num-=value[i];
                    str+=symbol[i];
                }
            }
            return str;
        }
};
