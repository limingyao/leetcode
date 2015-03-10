// Pascal's Triangle

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > result;
        for(int i=0;i<numRows;++i){
            vector<int> kRow;
            kRow.clear();
            kRow.push_back(1);
            for(int j=1;j<=i;++j){
                if(j==i){
                    kRow.push_back(1);
                }else{
                    kRow.push_back(result[i-1][j]+result[i-1][j-1]);
                }
            }
            result.push_back(kRow);
        }
        return result;
    }
};
