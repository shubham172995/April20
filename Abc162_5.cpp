#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lloop(i, a, b) for(ll i=a;i<(ll)b; i++)
#define loop(i, a, b) for(int i=a;i<b;i++)
#define pool(i, a, b) for(int i=a;i>b;i--)
#define pooll(i, a, b) for(ll i=a;i>b;i--)

#define MOD 1000000007

ll fastpower(ll a, ll b){
    ll res = 1;
    a %= MOD;
    while(b){
        if(b&1) res = (res * a) % MOD;
        a *= a; a %= MOD;
        b >>= 1;
    }
    return res;
}

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	vector<ll> a(k+1);
	pool(i, k, 0){
		ll multiples=k/i;
		multiples=fastpower(multiples, n);
		multiples%=MOD;
		ll temp=0;
		for(int j=2*i;j<=k;j+=i){
			temp=(temp+a[j])%MOD;
		}
		a[i]=(multiples-temp+MOD)%MOD;
	}
	//cout<<a[2]<<endl;
	//a[i] is the number of sequences with GCD of k. So, now, we need the sum of all GCDs. So, i*a[i] gives that sum for all sequences with gcd=i.
	ll ans=0;
	loop(i, 1, k+1){
		ll temp=(a[i]%MOD*i%MOD)%MOD;
		ans=(ans+temp)%MOD;
	}
	cout<<ans<<endl;
	return 0;
}