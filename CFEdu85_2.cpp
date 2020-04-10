#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lloop(i, a, b) for(ll i=a;i<(ll)b; i++)
#define loop(i, a, b) for(int i=a;i<b;i++)

int main(){
	int t;
	cin>>t;
	while(t--){
		ll n, x;
		cin>>n>>x;
		vector<ll> a(n);
		lloop(i, 0, n)
			cin>>a[i];
		sort(a.begin(), a.end());
		double sum=0.0, idx=-1;
		lloop(i, 0, n){
			sum+=a[i];
			if(a[i]>=x&&idx==-1){
				idx=idx==-1?i:idx;
			}
		}
		if(idx==-1){
			cout<<"0\n";
			continue;
		}
		double temp=(sum+0.0)/n;
		if(temp>=x){
			cout<<n<<endl;
			continue;
		}
		ll ans=0;
		lloop(i, 0, n){
			temp=(sum+0.0-a[i])/(n-i-1);
			if(temp>=x){
				ans=n-i-1;
				break;
			}
			sum-=a[i];
		}
		//cout<<idx<<" "<<ans<<endl;
		/*for(ll i=idx-1;i>=0;i--){
			float temp=sum+a[i];
			temp=(temp+0.0)/(ans+1);
			//cout<<temp<<endl;
			if(temp<x)
				break;
			sum=sum+a[i];
			ans+=1;
		}*/
		cout<<ans<<endl;
	}
	return 0;
}