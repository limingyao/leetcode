// Rotate Array

class Solution {
public:
    void reverse(int nums[], int bgn, int end){
        while(bgn<end){
            swap(nums[bgn++],nums[end--]);
        }
    }

    void rotate(int nums[], int n, int k) {
        if(n<1){
            return;
        }
        k=k%n;
        if(k<1){
            return;
        }
        reverse(nums,0,n-k-1);
        reverse(nums,n-k,n-1);
        reverse(nums,0,n-1);
    }
};

// method 2.1:
// 一次移动一个位置，for

// method 2.2:
// 一次移动一个位置，递归

// method 3.1:
// very very good solution
// Every swap will put one number into its correct position, so the running time is O(n)
void rotate(int nums[], int n, int k) {
    for (; k %= n; n -= k)
        for (int i = 0; i < k; i++)
            swap(*nums++, nums[n - k]);
}

// method 3.2:
// very very good solution
// 直接移动到对应的位置,循环移动
void rotate(int nums[], int n, int k) {
    if(n==0) return;
    if(k==0) return;
    k = k%n;
    int cycle = 0;
    int next = 0;
    int tmp = nums[next];
    for ( int i = 0; i< n; i++) {
        next = (next+k)%n;
        swap(nums[next], tmp);
        if(cycle==next){
            next ++;
            cycle = next;
            tmp = nums[next];
        }
    }
}
