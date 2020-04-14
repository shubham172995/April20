#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lloop(i, a, b) for(ll i=a;i<(ll)b; i++)
#define loop(i, a, b) for(int i=a;i<b;i++)
#define pool(i, a, b) for(int i=a;i>b;i--)
#define pooll(i, a, b) for(ll i=a;i>b;i--)

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		ll n;
		cin>>n;
		vector<ll> a(n);
		lloop(i, 0, n)
			cin>>a[i];
		if(n==1){
			cout<<"0\n";
			continue;
		}
		int u=1, s=0, temp=0;
		sort(a.begin(), a.end());
		lloop(i, 1, n){
			if(a[i]!=a[i-1]){
				++u;
				s=s>temp?s:temp;
				temp=0;
			}
			else temp=temp==0?2:temp+1;
		}
		s=s>temp?s:temp;
		u=s>0?u-1:u;
		//cout<<s<<" "<<u<<endl;
		if(u>=s){
			if(s)
				cout<<s<<endl;
			else cout<<"1\n";
		}
		else{
			if(s-u>1)
				cout<<u+1<<endl;
			else cout<<u<<endl;
		}
	}
	return 0;
}