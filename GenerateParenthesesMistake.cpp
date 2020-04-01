class Solution {
public:
    void solve(vector<string>& res, int n, int m, string temp){
        //cout<<temp<<" "<<n<<endl;
        if(n==0&&m==0){
            res.push_back(temp);
            return;
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++)
                temp+='(';
            solve(res, n-i, m, temp);
            for(int j=0;j<i;j++)
                temp+=')';
            solve(res, n-i, m-i, temp);
            temp=temp.substr(0, temp.length()-2*i);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string temp="";
        solve(res, n, n, temp);
        return res;
    }
};