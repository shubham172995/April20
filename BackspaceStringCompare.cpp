class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> a, b;
        for(int i=0;i<S.length();i++){
            if(S[i]!='#')
                a.push(S[i]);
            else if(S[i]=='#'&&a.size())
                a.pop();
        }
        for(int i=0;i<T.length();i++){
            if(T[i]!='#')
                b.push(T[i]);
            else if(T[i]=='#'&&b.size())
                b.pop();
        }
        if(a.size()!=b.size()){
            return false;
        }
        while(1){
            if(a.size()==0&&b.size()==0)
                return true;
            if(a.top()!=b.top())
                return false;
            if(a.top()==b.top()){
                a.pop();
                b.pop();
            }
        }
    }
};