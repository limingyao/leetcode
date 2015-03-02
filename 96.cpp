// Unique Binary Search Trees

/*

G(n)：n个数的时候的方案数
F(i,n)：以i为根节点，且有n个数的时候的方案数

1.G(n) = F(1,n)+F(2,n)+……+F(n,n)
2.G(0) = 1
3.G(1) = 1
4.F(i,n) = G(i-1)*G(n-i)
由1、2、3、4，得
G(n) = G(0)*G(n-1)+G(1)*G(n-2)+……+G(n-1)*G(0)

*/

class Solution {
public:
    int numTrees(int n) {
        int* dp = new int[n+1];
        dp[0]=dp[1]=1;
        for(int i=2;i<=n;i++){
            for(int j=0;j<i;j++){
                dp[i]+=dp[j]*dp[i-j-1];
            }
        }
        int ans = dp[n];
        delete[] dp;
        return ans;
    }
};
