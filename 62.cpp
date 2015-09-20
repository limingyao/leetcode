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
