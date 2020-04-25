#include<bits/stdc++.h>
using namespace std;

int main(){
    int prev=1, t;
    int n;
    cin>>t;
    while(t--){
        long long int n, num=0, den=0;
        prev=1;
        cin>>n;
        if(n==1){
            cout<<"TERM "<<n<<" IS 1/1\n";
            continue;
        }
        int i=2;
        while(prev<n){
            prev+=i;
            ++i;
        }
        if(prev>=n){
            prev-=i-1;
        }
        //cout<<"Hey "<<i<<" "<<prev<<endl;
        if(i%2!=0){
            num=1;
            for(int j=prev+1;j<n;j++){
                ++num;
            }
            cout<<"TERM "<<n<<" IS "<<num<<"/"<<i-num<<endl;
        }
        else if(i%2==0){
            num=i-1;
            for(int j=prev+1;j<n;j++){
                --num;
            }
            cout<<"TERM "<<n<<" IS "<<num<<"/"<<i-num<<endl;
        }          
    }
    return 0;
}