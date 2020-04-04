#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lloop(i, a, b) for(ll i=a;i<(ll)b; i++)
#define loop(i, a, b) for(int i=a;i<b;i++)

int main(){
	int t;
	cin>>t;
	for(int x=1;x<=t;x++){
		string s;
		cin>>s;
		stack<char> op;
		string ans="";
		loop(i, 0, s.length()){
			int digit=s[i]-'0';
			if(digit==op.size())
				ans+=s[i];
			else if(digit<op.size()){
				int temp=op.size()-digit;
				while(temp--){
					op.pop();
					ans+=')';
				}
				ans+=s[i];
			}
			else{
				int temp=digit-op.size();
				loop(j, 0, temp){
					op.push('(');
					ans+='(';
				}
				ans+=s[i];
			}
		}
		while(op.size()){
			ans+=')';
			op.pop();
		}
		cout<<"Case #"<<x<<": "<<ans<<endl;
	}
	return 0;
}