// Rotate Array

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

void reverse(int nums[], int start, int end){
    int i=0;
    while(start+i<end-i){
        int t = nums[start+i];
        nums[start+i] = nums[end-i];
        nums[end-i] = t;
        i++;
    }
}
