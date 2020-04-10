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
		int pi=0, ci=0;
		vector<int> p(n), c(n);
		loop(i, 0, n){
			cin>>p[i]>>c[i];
		}
		bool flag=false;
			if(p[0]<c[0]){
			cout<<"NO\n";
			continue;
		}
		loop(i, 1, n){
			int a, b;
			a=p[i]-p[i-1];
			b=c[i]-c[i-1];
			if(a<0||b<0){
				flag=true;
				break;
			}
			if(b>a){
				flag=true;
				break;
			}
			if(c[i]>p[i]){
				flag=true;
				break;
			}
		}
		if(flag)
			cout<<"NO\n";
		else cout<<"YES\n";
	}
	return 0;
}