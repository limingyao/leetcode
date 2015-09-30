// Move Zeroes

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int cur=0,last=0;cur<nums.size();++cur) {
            if(nums[cur]!=0) {
                swap(nums[cur], nums[last++]);
            }
        }
    }
};
