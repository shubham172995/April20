#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lloop(i, a, b) for(ll i=a;i<(ll)b; i++)
#define loop(i, a, b) for(int i=a;i<b;i++)

int main(){
	int n;
	cin>>n;
	string s="";
	getchar();
	cin>>s;
	ll ans=0;
	int count[n][3];
	loop(i, 0, n)
		count[i][0]=count[i][1]=count[i][2]=0;
	for(int i=n-1;i>=0;i--){
		if(s[i]=='R')
			++count[i][0];
		else if(s[i]=='G')
			++count[i][1];
		else if(s[i]=='B')
			++count[i][2];
		if(i==n-1)
			continue;
		count[i][0]+=count[i+1][0];
		count[i][1]+=count[i+1][1];
		count[i][2]+=count[i+1][2];
	}
	loop(i, 0, n-2){
		loop(j, i+1, n-1){
			if(s[i]!=s[j]){
				if(j+j-i < n && s[j+j-i]!=s[j] && s[j+j-i]!=s[i])
					--ans;
				bool r=0, g=0, b=0;
				if(s[i]=='R'||s[j]=='R')
					r=1;
				if(s[i]=='G'||s[j]=='G')
					g=1;
				if(s[i]=='B'||s[j]=='B')
					b=1;
				if(!r)
					ans+=count[j+1][0];
				if(!g)
					ans+=count[j+1][1];
				if(!b)
					ans+=count[j+1][2];
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}