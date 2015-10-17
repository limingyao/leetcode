// Word Pattern

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> vec = split(str);
        int len = pattern.size();
        if(pattern.size() != vec.size()) {
            return false;
        }
        map<char,string> k_v;
        map<string,char> v_k;
        for(int i=0; i<len; ++i) {
            if(k_v.find(pattern[i])!=k_v.end()) {
                if((k_v.find(pattern[i])->second)!=vec[i]) {
                    return false;
                }
            } else {
                k_v[pattern[i]] = vec[i];
                
                if(v_k.find(vec[i])==v_k.end()) {
                    v_k[vec[i]] = pattern[i];
                } else {
                    if((v_k.find(vec[i]) -> second) != pattern[i]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
private:
    vector<string> split(const string str) {
        vector<string> vec;
        string buf;
        int len = str.size();
        for(int i=0; i<len; ++i) {
            if(str[i]==' ') {
                vec.push_back(buf);
                buf = "";
            } else {
                buf += str[i];
            }
        }
        if(buf.size()!=0) {
            vec.push_back(buf);
        }
        return vec;
    }
};
