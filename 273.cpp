// Integer to English Words

class Solution {
public:
    string numberToWords(int num) {
        if(num==0) {
            return "Zero";
        }
        else {
            string ret = int_string(num);
            return ret.substr(ret.find_first_not_of(' '));
        }
    }

private:
    static const char* const less_twenty[];
    static const char* const less_hundred[];
    const int billion = 1000000000;
    const int million = 1000000;
    const int thousand = 1000;
    const int hundred = 100;
    
    string int_string(int num) {
        if(num>=billion) {
            return int_string(num/billion) + " Billion" + int_string(num-billion*(num/billion));
        } else if(num>=million) {
            return int_string(num/million) + " Million" + int_string(num-million*(num/million));
        } else if (num>=thousand) {
            return int_string(num/thousand) + " Thousand" + int_string(num-thousand*(num/thousand));
        } else if (num>=hundred) {
            return int_string(num/hundred) + " Hundred" + int_string(num-hundred*(num/hundred));
        } else if (num>=20) {
            return string(" ") + less_hundred[num/10-2] + int_string(num-10*(num/10));
        } else if(num>=1) {
            return string(" ") + less_twenty[num-1];
        }
        return "";
    }
};
const char* const Solution::less_twenty[] =  {"One", "Two", "Three", "Four","Five","Six","Seven","Eight","Nine","Ten", "Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
const char* const Solution::less_hundred[] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};


// Method 2:
class Solution {
public:
    string numberToWords(int num) {
        int i = 0;
        string word;
        while(num) {
            int n = num % 1000;
            num /= 1000;
            string ret = helper(n);
            if(ret.size()>0){
                if(i>0){
                    word = ret + " " + unit[i] + (word.size() ? " " + word : word);
                }else{
                    word = ret;
                }
            }
            ++i;
        }
        return word.size() ? word : "Zero";
    }
private:
    static const char* const less_twenty[];
    static const char* const less_hundred[];
    static const char* const unit[];

    string helper(int num) {
        string word = "";
        if(num == 0){
            return word;
        }
        if(num/100!=0) {
            word = word + less_twenty[num/100] + " " + unit[0];
            num %= 100;
        }
        if(num>=20) {
            word = word.size() ? word + " " : word;
            word += less_hundred[num/10];
            num %= 10;
        }
        if(num > 0) {
            word = word.size() ? word + " " : word;
            word += less_twenty[num];
        }
        return word;
    }
};

const char* const Solution::less_twenty[] =  {"", "One", "Two", "Three", "Four","Five","Six","Seven","Eight","Nine","Ten", "Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
const char* const Solution::less_hundred[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
const char* const Solution::unit[] = {"Hundred", "Thousand", "Million", "Billion", "Triliion"};

