#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lloop(i, a, b) for(ll i=a;i<(ll)b; i++)
#define loop(i, a, b) for(int i=a;i<b;i++)
#define pool(i, a, b) for(int i=a;i>b;i--)
#define pooll(i, a, b) for(ll i=a;i>b;i--)
#define pb push_back

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n, m;
		scanf("%d %d", &n, &m);
		int num=1<<n;
		vector<bool> a(1025);
		loop(i, 0, m){
			int temp;
			cin>>temp;
			a[temp-1]=1;
		}
		int ans=0;
		int inc=1, idx=1;
		while(n--){
			vector<bool> temp(1025);
			num>>=1;
			for(int i=0;i<num;i++){
				if(a[i<<1]^a[(i<<1)+1])
					++ans;
				temp[i]=(a[i<<1]&a[(i<<1)+1]);
			}
			a=temp;
		}
		cout<<ans<<endl;
	}
	return 0;
}