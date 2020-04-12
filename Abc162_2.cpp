#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lloop(i, a, b) for(ll i=a;i<(ll)b; i++)
#define loop(i, a, b) for(int i=a;i<b;i++)

int main(){
	ll sum=0;
	ll n;
	cin>>n;
	lloop(i, 1, n+1){
		if(i%3&&i%5)
			sum+=i;
	}
	cout<<sum<<endl;
	return 0;
}