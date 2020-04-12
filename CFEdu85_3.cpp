#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lloop(i, a, b) for(ll i=a;i<(ll)b; i++)
#define loop(i, a, b) for(int i=a;i<b;i++)

int t, n;
ll a[300013], b[300013];

int main(){
	scanf("%d", &t);
	while(t--){
        scanf("%d", &n);
        loop(i, 0, n)
            scanf("%lld %lld", &a[i], &b[i]);
        ll ans=0, mi=1e18;
        loop(i, 0, n){
        	int idx=(i+1)%n;
            ll temp=a[idx]>b[i]?b[i]:a[idx];
            ans+=a[idx]-temp;
            mi=min(mi, temp);
        }
        ans+=mi;
        cout<<ans<<endl;
	}
	return 0;
}