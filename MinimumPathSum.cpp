class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size()==0)
            return 0;
        vector<vector<int> > sum(grid.size());
        for(int i=0;i<grid.size();i++)
            sum[i].resize(grid[0].size());
        sum[0][0]=grid[0][0];
        for(int i=1;i<grid.size();i++)
            sum[i][0]=grid[i][0]+sum[i-1][0];
        for(int i=1;i<grid[0].size();i++)
            sum[0][i]=grid[0][i]+sum[0][i-1];
        for(int i=1;i<grid.size();i++){
            for(int j=1;j<grid[0].size();j++){
                sum[i][j]=grid[i][j]+min(sum[i-1][j], sum[i][j-1]);
            }
        }
        return sum[sum.size()-1][sum[0].size()-1];
    }
};