class Solution {
public:
    void solve(vector<string>& res, int n, int m, string temp){
        //cout<<temp<<" "<<n<<endl;
        if(n==0&&m==0){
            res.push_back(temp);
            return;
        }
        if(n>0)
            solve(res, n-1, m, temp+'(');
        if(m>n&&m>0)
            solve(res, n, m-1, temp+')');
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string temp="";
        solve(res, n, n, temp);
        return res;
    }
};