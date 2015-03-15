// Length of Last Word

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        if(s==NULL){
            return 0;
        }
        int count = 0;
        bool flag = true;
        while(*s!='\0'){
            if(*s!=' '){
                if(!flag){
                    count = 0;
                    flag = true;
                }
                ++count;
            } else {
                flag = false;
            }
            ++s;
        }
        return count;
    }
};

int lengthOfLastWord(const char* s) {
    int len = 0;
    while (*s) {
        if (*s++ != ' ') // 这里用得很巧妙
            ++len;
        else if (*s && *s != ' ')
            len = 0;
    }
    return len;
}
