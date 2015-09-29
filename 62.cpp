// Unique Paths

class Solution {
public:
    int uniquePaths(int m, int n) {
        init();
        return com[m+n-2][m-1];
    }
private:
    int com[105][105];
    void init(){
        com[0][0] = 1;
        for(int i=1;i<105;i++){
            com[i][0] = 1;
            com[i][i] = 1;
            for(int j=1;j<i;j++){
                com[i][j] = com[i-1][j] + com[i-1][j-1]; 
            }
        }
    }
};


// DP solution
public class Solution {
    public int uniquePaths(int m, int n) {
        Integer[][] map = new Integer[m][n];
        for(int i = 0; i<m;i++){
            map[i][0] = 1;
        }
        for(int j= 0;j<n;j++){
            map[0][j]=1;
        }
        for(int i = 1;i<m;i++){
            for(int j = 1;j<n;j++){
                map[i][j] = map[i-1][j]+map[i][j-1];
            }
        }
        return map[m-1][n-1];
    }
}
