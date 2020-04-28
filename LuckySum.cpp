#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lloop(i, a, b) for(ll i=a;i<(ll)b; i++)
#define loop(i, a, b) for(int i=a;i<b;i++)
#define pool(i, a, b) for(int i=a;i>b;i--)
#define pooll(i, a, b) for(ll i=a;i>b;i--)
#define pb push_back

ll l, r;
set<ll> S;

int func(ll start){
	S.insert(start);
	if(start<r){
		func(start*10+4);
		func(start*10+7);
	}
}

int main(){
	cin>>l>>r;
	func(0);
	ll ans=0;
	while(l<=r){
		set<ll>::iterator it=S.lower_bound(l);
		ans+=*it*(min(r, *it)-l+1);
		l=*it+1;
	}
	cout<<ans<<endl;
	return 0;
}