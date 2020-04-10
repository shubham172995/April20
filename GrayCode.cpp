class Solution {
public:
    void check(string a, string b, map<string, bool>& m, vector<string>& col, int siz){
        if(col.size()==siz)
            return;
        if(m[b])
            return;
        int count=0;
        for(int i=0;i<a.length();i++){
            if(a[i]!=b[i])
                ++count;
        }
        if(count==1){
            m[b]=1;
            col.push_back(b);
        }
        else return;
        a=b;
        for(int i=0;i<b.length();i++){
            if(b[i]=='0')
                b[i]='1';
            else if(b[i]=='1')
                b[i]='0';
            check(a, b, m, col, siz);
            b=a;
        }
    }
    vector<int> grayCode(int n) {
        int siz=pow(2, n);
        /*vector<int> res(size);*/
        string a="";
        for(int i=0;i<n;i++)
            a+='0';
        map<string, bool> m;
        m[a]=1;
        string b=a;
        b[0]='1';
        vector<string> col;
        col.push_back(a);
        check(a, b, m, col, siz);
        vector<int> ans;
        for(int i=0;i<col.size();i++){
            //cout<<col[i]<<endl;
            int temp=0;
            for(int j=col[i].length()-1;j>=0;j--){
                temp+=((col[i][j]-'0')*(pow(2, j)));
            }
            ans.push_back(temp);
        }
        return ans;
    }
};