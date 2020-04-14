#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lloop(i, a, b) for(ll i=a;i<(ll)b; i++)
#define loop(i, a, b) for(int i=a;i<b;i++)
#define pool(i, a, b) for(int i=a;i>b;i--)
#define pooll(i, a, b) for(ll i=a;i>b;i--)

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		ll n;
		cin>>n;
		ll ways=n/2;
		ways=n%2==0?ways-1:ways;
		cout<<ways<<endl;
	}
	return 0;
}