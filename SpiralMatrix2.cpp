class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > a(n);
        if(n==0)
            return a;
        for(int i=0;i<n;i++)
            a[i].resize(n);
        int lc=0, rc=n-1, ur=0, lr=n-1, dir=0;
        int i=0, j=0;
        int num=1;
        while(num<=n*n){
            if(dir==0){
                if(j<rc){
                    a[i][j]=num;
                    ++num;
                    ++j;
                }
                else if(j==rc){
                    ur+=1;
                    dir=1;
                    a[i][j]=num;
                    ++num;
                    ++i;
                }
            }
            else if(dir==1){
                if(i<lr){
                    a[i][j]=num;
                    ++num;
                    ++i;
                }
                else if(j==lr){
                    a[i][j]=num;
                    ++num;
                    dir=2;
                    --rc;
                    --j;
                }
            }
            else if(dir==2){
                if(j>lc){
                    a[i][j]=num;
                    ++num;
                    --j;
                }
                else if(j==lc){
                    dir=4;
                    lr-=1;
                    a[i][j]=num;
                    --i;
                    ++num;
                }
            }
            else{
                if(i>ur){
                    a[i][j]=num;
                    ++num;
                    --i;
                }
                else if(i==ur){
                    dir=0;
                    lc+=1;
                    a[i][j]=num;
                    ++num;
                    ++j;
                }
            }
        }
        return a;
    }
};