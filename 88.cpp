// Merge Sorted Array

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0, j=0, cur = 0;
        while(i < m && j < n)
        {
            if(nums1[cur] > nums2[j])
            {
                nums1.insert(nums1.begin() + cur, nums2[j]);
                j++;
            }
            else
            {
                i++;
            }
            cur++;
        }
        while(i<m)
        {
            i++;
            cur++;
        }
        while(j<n)
        {
            nums1.insert(nums1.begin() + cur, nums2[j]);
            j++;
            cur++;
        }
        nums1.erase(nums1.begin() + cur, nums1.begin() + nums1.size());
    }
};

Method 1:
while(n>0) A[m+n-1] = (m==0||B[n-1] > A[m-1]) ? B[--n] : A[--m];
