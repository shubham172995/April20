class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > a;
        vector<int> b, temp(n+1);
        string s="";
        for(int i=0;i<n;i++){
            s+='0';
            temp[i+1]=i+1;
        }
        for(int i=0;i<k;i++)
            s[n-i-1]='1';
        do{
            for(int i=0;i<n;i++){
                if(s[i]=='0')
                    continue;
                b.push_back(temp[i+1]);
            }
            a.push_back(b);
            b.clear();
        }while(next_permutation(s.begin(), s.end()));
        return a;
    }
};