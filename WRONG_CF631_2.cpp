#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lloop(i, a, b) for(ll i=a;i<(ll)b; i++)
#define loop(i, a, b) for(int i=a;i<b;i++)

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		ll n;
		cin>>n;
		vector<ll> a(n);
		lloop(i, 0, n)
			cin>>a[i];
		ll sum=0;
		ll max=0;
		vector<pair<ll, ll> > ans;
		lloop(i, 0, n){
			max=max>a[i]?max:a[i];
			sum+=a[i];
			ll temp=(i+1)*(i+2);
			temp/=2;
			if(temp==sum){
				if(i==n-1)
					continue;
				ll k=0;
				lloop(j, i+1, n){
					k+=a[j];
				}
				//cout<<k<<endl;
				temp=n-(i+1);
				temp=temp*(temp+1);
				temp/=2;
				//cout<<temp<<endl;
				if(temp==k){
					pair<ll, ll> l;
					l.first=i+1;
					l.second=n-(i+1);
					ans.push_back(l);
				}
			}
		}
		vector<int> check(max+1);
		max=0;
		lloop(i, 0, n){
			++check[a[i]];
			max=max>check[a[i]]?max:check[a[i]];
		}
		if(max>2)
			cout<<"0\n";
		else{
			cout<<ans.size()<<endl;
			loop(i, 0, ans.size())
				cout<<ans[i].first<<" "<<ans[i].second<<endl;
		}
	}
	return 0;
}