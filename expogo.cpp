#include<bits/stdc++.h>
using namespace std;
#define ll long long int

map<pair<ll, ll>, bool> m;
string res;

bool check(ll x, ll y, int power, ll curx, ll cury, string ans){
    //cout<<curx<<" "<<cury<<endl;
    if(curx==x&&cury==y){
        res=ans.length()<res.length()?ans:res;
        return true;
    }
    if(abs(curx)>abs(x)||abs(cury)>abs(y))
        return false;
    pair<ll, ll> p=make_pair(curx, cury);
    bool flag=false;
    if(check(x, y, power+1, curx+pow(2,power), cury, ans+'E')){
        flag = true;
    }
    if(check(x, y, power+1, curx-pow(2,power), cury, ans+'W')){
        flag = true;
    }
    if(check(x, y, power+1, curx, cury+pow(2,power), ans+'N')){
        flag = true;
    }
    if(check(x, y, power+1, curx, cury-pow(2,power), ans+'S')){
        flag = true;
    }
    if(flag)
        return true;
    return false;
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=1;i<=t;i++){
        res="EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE";
        ll x, y;
        cin>>x>>y;
        pair<ll, ll> p=make_pair(0,0);
        m[p]=1;
        bool flag=check(x, y, 0, 0, 0, "");
        cout<<"Case #"<<i<<": ";
        if(flag)
            cout<<res<<endl;
        else cout<<"IMPOSSIBLE\n";
    }
}