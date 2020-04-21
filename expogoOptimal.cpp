#include<bits/stdc++.h>
using namespace std;
#define ll long long int

string res;

int main(){
    int t;
    scanf("%d", &t);
    for(int i=1;i<=t;i++){
        res="";
        ll x, y, curx=0, cury=0;
        cin>>x>>y;
        curx=x;
        cury=y;
        x=abs(x);
        y=abs(y);
        if((x+y)%2==0){
            cout<<"Case #"<<i<<": IMPOSSIBLE\n";
            continue;
        }
        while(1){
            //cout<<x<<" "<<y<<endl;
            if(x==0&&y==0)
                break;
            if(x==1&&y==0){
                res+='E';
                x=0;
                /*ll tempx=x+1;
                tempx>>=1;
                if(tempx%2!=0){
                    res+='W';
                    x=tempx;
                }
                else{
                    res+='E';
                    tempx=x-1;
                    tempx>>=1;
                    x=tempx;
                }*/
            }
            else if(y==1&&x==0){
                res+='N';
                y=0;
                /*ll tempy=y+1;
                tempy>>=1;
                if(tempy%2!=0){
                    res+='S';
                    y=tempy;
                }
                else{
                    res+='N';
                    tempy=y-1;
                    tempy>>=1;
                    y=tempy;
                }*/
            }
            else if(x%2!=0){
                ll tempx=x+1;
                ll tempy=y;
                tempx>>=1;
                tempy>>=1;
                if((tempx+tempy)%2!=0){
                    res+='W';
                    x=tempx;
                    y=tempy;
                }
                else{
                    tempx=x-1;
                    tempx>>=1;
                    x=tempx;
                    y=tempy;
                    res+='E';
                }
            }
            else if(y%2!=0){
                ll tempx=x;
                ll tempy=y+1;
                tempx>>=1;
                tempy>>=1;
                if((tempx+tempy)%2!=0){
                    res+='S';
                    x=tempx;
                    y=tempy;
                }
                else{
                    x=tempx;
                    tempy=y-1;
                    tempy>>=1;
                    res+='N';
                    y=tempy;
                }
            }
        }
        if(curx<0){
            for(int i=0;i<res.length();i++){
                if(res[i]=='E')
                    res[i]='W';
                else if(res[i]=='W')
                    res[i]='E';
            }
        }
        if(cury<0){
            for(int i=0;i<res.length();i++){
                if(res[i]=='N')
                    res[i]='S';
                else if(res[i]=='S')
                    res[i]='N';
            }
        }
        cout<<"Case #"<<i<<": "<<res<<endl;
    }
}