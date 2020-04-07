#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lloop(i, a, b) for(ll i=a;i<(ll)b; i++)
#define loop(i, a, b) for(int i=a;i<b;i++)

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int p;
		cin>>p;
		vector<int> h(p);
		loop(i, 0, p){
			cin>>h[i];
		}
		int ans=0;
		int weekday=1;
		loop(i, 1, n+1){
			if(weekday==6||weekday==7){
				weekday=weekday==7?1:weekday+1;
				continue;
			}
			++weekday;
			//cout<<i<<" Hey "<<weekday<<" ";
			loop(j, 0, p){
				if(i%h[j]==0){
					++ans;
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}