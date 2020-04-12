#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lloop(i, a, b) for(ll i=a;i<(ll)b; i++)
#define loop(i, a, b) for(int i=a;i<b;i++)

int main(){
	string s;
	cin>>s;
	if(s[0]=='7'||s[1]=='7'||s[2]=='7')
		cout<<"Yes\n";
	else cout<<"No\n";
	return 0;
}