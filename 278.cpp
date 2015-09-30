// First Bad Version

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int bgn = 1;
        int end = n;
        while(bgn < end) {
            // 注意：这里会溢出
            int mid = bgn + (end - bgn) / 2;
            if(isBadVersion(mid)){
                // bad version
                end = mid;
            }else{
                bgn = mid + 1;
            }
        }
        return bgn;
    }
};
