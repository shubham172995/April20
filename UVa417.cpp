#include<bits/stdc++.h>
using namespace std;
int code;
map<string, int> m;

void count(string s, int l){
    if(l==s.length()){
        m[s]=code++;
        return;
    }
    char ch;
    if(s.length()==0){
        ch='a';
    }
    else ch=s[s.length()-1]+1;
    for(char c=ch;c<='z';c++){
        count(s+c, l);
    }
}

int main(){
    code=1;
    string s;
    for(int i=1;i<=5;i++){
        count("", i);
    }
    while(cin>>s){
        cout<<m[s]<<endl;
    }
    return 0;
}