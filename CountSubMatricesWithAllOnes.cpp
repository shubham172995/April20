class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        if(matrix.size()==0)
            return 0;
        vector<vector<int> > dp(matrix.size(), vector<int> (matrix[0].size()));
        for(int i=0;i<matrix.size();i++)
            dp[i][0]=matrix[i][0];
        for(int i=0;i<matrix[0].size();i++)
            dp[0][i]=matrix[0][i];
	//For every element, see the minimum sized square that its adjacent elements can form and increase it by one for current element.
        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[0].size();j++){
                if(matrix[i][j]==0)
                    dp[i][j]=0;
                else{
                    int temp=min(dp[i-1][j-1], dp[i-1][j]);
                    temp=min(temp, dp[i][j-1]);
                    dp[i][j]=temp+1;
                }
            }
        }
        int ans=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                ans+=dp[i][j];
            }
        }
        return ans;
    }
};