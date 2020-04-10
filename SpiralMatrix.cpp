class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int i=0, j=0, dir=0;
        vector<int> ans;
        if(matrix.size()==0)
            return ans;
        int ru=0, rd=matrix.size()-1, cl=0, cr=matrix[0].size()-1;
        int num=matrix.size()*matrix[i].size();
        while(1){
            if(ans.size()==num)
                break;
            if(dir==0){
                if(j==cr){
                    ++ru;
                    dir=1;
                }
                else{
                    ans.push_back(matrix[i][j]);
                    ++j;
                }
            }
            else if(dir==1){
                if(i==rd){
                    --cr;
                    dir=2;
                }
                else{
                    ans.push_back(matrix[i][j]);
                    ++i;
                }
            }
            else if(dir==2){
                if(j==cl){
                    --rd;
                    dir=3;
                }
                else{
                    ans.push_back(matrix[i][j]);
                    --j;
                }
            }
            else if(dir==3){
                if(i==ru){
                    ++cl;
                    dir=0;
                }
                else{
                    ans.push_back(matrix[i][j]);
                    --i;
                }
            }
        }
        return ans;
    }
};