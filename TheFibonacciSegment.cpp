#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lloop(i, a, b) for(ll i=a;i<(ll)b; i++)
#define loop(i, a, b) for(int i=a;i<b;i++)
#define pool(i, a, b) for(int i=a;i>b;i--)
#define pooll(i, a, b) for(ll i=a;i>b;i--)
#define pb push_back

int main(){
	int n;
	scanf("%d", &n);
	vector<ll> a(n);
	loop(i, 0, n)
		cin>>a[i];
	int ans=0, temp=2;
	loop(i, 2, n){
		if(a[i]==a[i-1]+a[i-2])
			++temp;
		else{
			ans=ans<temp?temp:ans;
			temp=2;
		}
	}
	ans=ans<temp?temp:ans;
	if(n<=2)
		ans=n;
	cout<<ans<<endl;
	return 0;
}