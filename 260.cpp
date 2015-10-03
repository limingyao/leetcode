// Single Number III

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int res = 0;
        for(int i=0;i<nums.size();++i){
            res ^= nums[i];
        }
        int index = find_first_one(res);
        int num = (1<<index);
        int num1 = 0;
        int num2 = 0;
        for(int i=0;i<nums.size();++i){
            if(num&nums[i]){
                num1 ^= nums[i];
            }else{
                num2 ^= nums[i];
            }
        }
        vector<int> vec;
        vec.push_back(num1);
        vec.push_back(num2);
        return vec;
    }
private:
    int find_first_one(int num){
        int index = 0;
        while((num&1)==0){
            num >>=1;
            ++index;
        }
        cout<<index<<endl;
        return index;
    }
};

// 优化
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int res = 0;
        for(int i=0;i<nums.size();++i){
            res ^= nums[i];
        }
        // Get its last set bit
        int num = res & (-res);
        // int lastBit = (aXorb & (aXorb - 1)) ^ aXorb;
        // int lowestOneBit = xXorY & (~(xXorY - 1));
        
        int num1 = 0;
        int num2 = 0;
        for(int i=0;i<nums.size();++i){
            if(num&nums[i]){
                num1 ^= nums[i];
            }else{
                num2 ^= nums[i];
            }
        }
        return vector<int>{num1,num2};
    }
};
