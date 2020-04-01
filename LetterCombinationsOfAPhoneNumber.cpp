class Solution {
public:
    void solve(vector<string>& a, string s, int i, vector<string>& res, string temp){
        //cout<<temp<<" ";
        if(i==s.length()){
            if(temp.length())
                res.push_back(temp);
            return;
        }
        //for(int j=i;j<s.length();j++){
            for(int k=0;k<a[s[i]-'0'].length();k++){
                temp+=a[s[i]-'0'][k];
                solve(a, s, i+1, res, temp);
                temp=temp.substr(0, temp.length()-1);
            }
        //}
    }
    vector<string> letterCombinations(string digits) {
        vector<string> a(10);
        a[2]="abc";
        a[3]="def";
        a[4]="ghi";
        a[5]="jkl";
        a[6]="mno";
        a[7]="pqrs";
        a[8]="tuv";
        a[9]="wxyz";
        /*for(int i=0;i<digits.length();i++){
            for(int j=0;j<a[digits[i]-'0'].length();j++){
                string ans+=
            }
        }*/
        vector<string> res;
        string temp="";
        solve(a, digits, 0, res, temp);
        return res;
    }
};