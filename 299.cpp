// Bulls and Cows

class Solution {
public:
    string getHint(string secret, string guess) {
        int cnts[10] = {0};
        size_t len = secret.size();
        for(int i = 0; i < len; ++ i) {
            ++ cnts[secret.at(i) - '0'];
        }
        int A = 0, B = 0;
        for(int i = 0; i < len; ++ i) {
            if(secret.at(i) == guess.at(i)) {
                -- cnts[secret.at(i) - '0'];
                ++ A;
            }
        }
        for(int i = 0; i < len; ++ i) {
            if (secret.at(i) != guess.at(i) && cnts[guess.at(i) - '0'] > 0) {
                -- cnts[guess.at(i) - '0'];
                ++ B;
            }
        }
        stringstream as, bs;
        as << A;
        bs << B;
        return as.str() + "A" + bs.str() + "B";
    }
};


class Solution {
public:
    // only contains digits 
    string getHint(string secret, string guess) {
        int aCnt = 0;
        int bCnt = 0;
        vector<int> sVec(10, 0); // 0 ~ 9 for secret
        vector<int> gVec(10, 0); // 0 ~ 9 for guess 
        if (secret.size() != guess.size() || secret.empty()) { return "0A0B"; }
        for (int i = 0; i < secret.size(); ++i) {
            char c1 = secret[i]; char c2 = guess[i];
            if (c1 == c2) {
                ++aCnt; 
            } else {
                ++sVec[c1-'0'];
                ++gVec[c2-'0'];
            }
        }
        // count b 
        for (int i = 0; i < sVec.size(); ++i) {
            bCnt += min(sVec[i], gVec[i]);
        }
        return to_string(aCnt) + 'A' + to_string(bCnt) + 'B';
    }
};
