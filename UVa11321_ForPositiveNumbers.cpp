#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lloop(i, a, b) for(ll i=a;i<(ll)b; i++)
#define loop(i, a, b) for(int i=a;i<b;i++)
#define pool(i, a, b) for(int i=a;i>b;i--)
#define pooll(i, a, b) for(ll i=a;i>b;i--)

int main(){
	while(1){
		int n, m;
		scanf("%d %d", &n, &m);
		if(n==0){
			cout<<n<<" "<<m<<endl;
			break;
		}
		vector<pair<int,ll> > a(n);
		loop(i, 0, n){
			ll temp;
			cin>>temp;
			pair<ll, int> p;
			p.first=temp%m;
			p.second=temp;
			a[i]=p;
		}
		cout<<endl;
		sort(a.begin(), a.end());
		map<int, int> odd, even;
		loop(i, 0, n){
			if(a[i].second%2==0){
				++even[a[i].first];
				cout<<" OKAY "<<a[i].second<<" "<<a[i].second%2<<" "<<even[a[i].first]<<endl;
			}
			else{
				++odd[a[i].first];
				cout<<" OKAY "<<a[i].second<<" "<<a[i].second%2<<" "<<odd[a[i].first]<<endl;
			}
		}
		vector<vector<int> > ans(m);
		loop(i, 0, m){
			ans[i].resize(even[i]+odd[i]);
		}
		/*loop(i, 0, m)
			cout<<ans[i].size()<<" ";
		cout<<endl;*/
		int idx=0;
		loop(i, 0, m){
			idx+=ans[i].size()-1;
			int k=0, ev=even[i]-1;
			//cout<<"Hey "<<a[idx].second<<endl;
			pool(j, ans[i].size()-1, -1){
				if(a[idx].second%2!=0){
					ans[i][k]=a[idx].second;
					++k;
				}
				else{
					ans[i][odd[i]+ev]=a[idx].second;
					--ev;
				}
				--idx;
			}
		idx+=ans[i].size()+1;
		}
		cout<<n<<" "<<m<<endl;
		loop(i, 0, m){
			loop(j, 0, ans[i].size())
				cout<<ans[i][j]<<endl;
		}
	}
	return 0;
}