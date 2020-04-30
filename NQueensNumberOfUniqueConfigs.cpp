class Solution {
public:
    void solve(vector<vector<string> >& ans, vector<string>& inter, int row, int q){
        /*cout<<row<<endl;
        for(int i=0;i<inter.size();i++)
            cout<<inter[i]<<endl;*/
        for(int i=0;i<inter.size();i++){
            if(inter[row][i]!='-'){
                stack<pair<int, int> > s;
                inter[row][i]='Q';
                ++q;
                if(row==inter.size()-1){
                    if(q==inter.size())
                        ans.push_back(inter);
                    inter[row][i]='.';
                    return;
                }
                for(int j=0;j<row;j++){
                    if(inter[j][i]=='.'){
                        inter[j][i]='-';
                        s.push(pair<int, int>(j, i));
                    }
                }
                for(int j=row+1;j<inter.size();j++)
                    if(inter[j][i]=='.'){
                        inter[j][i]='-';
                        s.push(pair<int, int>(j, i));
                    }
                for(int j=0;j<i;j++)
                    if(inter[row][j]=='.'){
                        inter[row][j]='-';
                        s.push(pair<int, int>(row, j));
                    }
                for(int j=i+1;j<inter.size();j++)
                    if(inter[row][j]=='.'){
                        inter[row][j]='-';
                        s.push(pair<int, int>(row, j));
                    }
                int ti=row-1, tj=i-1;
                while(ti>=0&&tj>=0){
                    if(inter[ti][tj]=='.'){
                        inter[ti][tj]='-';
                        s.push(pair<int, int>(ti, tj));
                    }
                    --ti;
                    --tj;
                }
                ti=row+1; tj=i+1;
                while(ti<inter.size()&&tj<inter.size()){
                    if(inter[ti][tj]=='.'){
                        inter[ti][tj]='-';
                        s.push(pair<int, int>(ti, tj));
                    }
                    ++ti;
                    ++tj;
                }
                ti=row-1; tj=i+1;
                while(ti>=0&&tj<inter.size()){
                    if(inter[ti][tj]=='.'){
                        inter[ti][tj]='-';
                        s.push(pair<int, int>(ti, tj));
                    }
                    --ti;
                    ++tj;
                }
                ti=row+1; tj=i-1;
                while(ti<inter.size()&&tj>=0){
                    if(inter[ti][tj]=='.'){
                        inter[ti][tj]='-';
                        s.push(pair<int, int>(ti, tj));
                    }
                    --tj;
                    ++ti;
                }
                
                solve(ans, inter, row+1, q);
                
                inter[row][i]='.';
                while(s.size()){
                    ti=s.top().first;
                    tj=s.top().second;
                    s.pop();
                    inter[ti][tj]='.';
                }
                /*for(int j=0;j<row;j++)
                    inter[j][i]='.';
                for(int j=row+1;j<inter.size();j++)
                    inter[j][i]='.';
                for(int j=0;j<i;j++)
                    inter[row][j]='.';
                for(int j=i+1;j<inter.size();j++)
                    inter[row][j]='.';
                ti=row-1; tj=i-1;
                while(ti>=0&&tj>=0){
                    inter[ti][tj]='.';
                    --ti;
                    --tj;
                }
                ti=row+1; tj=i+1;
                while(ti<inter.size()&&tj<inter.size()){
                    inter[ti][tj]='.';
                    ++ti;
                    ++tj;
                }
                ti=row-1; tj=i+1;
                while(ti>=0&&tj<inter.size()){
                    inter[ti][tj]='.';
                    --ti;
                    ++tj;
                }
                ti=row+1; tj=i-1;
                while(ti<inter.size()&&tj>=0){
                    inter[ti][tj]='.';
                    --tj;
                    ++ti;
                }*/
                --q;
            }
            else continue;
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> inter(n);
        if(n==0){
            ans.push_back(inter);
            return ans;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                inter[i]+='.';
            }
        }
        solve(ans, inter, 0, 0);
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<ans[i].size();j++){
                for(int k=0;k<ans[i][j].length();k++)
                    if(ans[i][j][k]=='-')
                        ans[i][j][k]='.';
            }
        }
        return ans;
    }
};