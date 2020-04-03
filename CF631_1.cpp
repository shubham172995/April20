#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lloop(i, a, b) for(ll i=a;i<(ll)b; i++)
#define loop(i, a, b) for(int i=a;i<b;i++)

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n, x;
		scanf("%d %d", &n, &x);
		vector<int> a(n), b(101);
		loop(i, 0, n)
			cin>>a[i];
		int v=0;
		loop(i, 0, n){
			vector<bool> c(101);
			c[a[i]]=1;
			b[a[i]]=1;
			loop(j, 0, n){
				if(c[a[j]])
					continue;
				c[a[j]]=1;
				if(a[j]<a[i])
					++b[a[i]];
			}
		}
		loop(i, 0, n){
			if((a[i]-b[a[i]])>x)
				continue;
			else if((a[i]-b[a[i]])==x){
				v=v>a[i]?v:a[i];
			}
			else if((a[i]-b[a[i]])<x){
				v=v>(b[a[i]]+x)?v:(b[a[i]]+x);
			}
		}
		if(v==0)
			v=x;
		cout<<v<<endl;
	}
	return 0;
}