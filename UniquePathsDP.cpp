class Solution {
public:
    /*int count(int m, int n, int i, int j){
        //cout<<i<<" "<<j<<" ";
        if(i>m||j>n)
            return 0;
        if(i==m&&j==n)
            return 1;
        return count(m, n, i+1, j)+count(m, n, i, j+1);
    }*/
    int uniquePaths(int m, int n) {
        vector<vector<int> > a(n, vector<int> (m, 1));
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                a[i][j]=a[i-1][j]+a[i][j-1];
            }
        }
        return a[n-1][m-1];
    }
};