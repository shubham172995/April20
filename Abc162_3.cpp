#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lloop(i, a, b) for(ll i=a;i<(ll)b; i++)
#define loop(i, a, b) for(int i=a;i<b;i++)

int gcd(int a, int b){
	if(b==0)
		return a;
	return gcd(b, a%b);
}

int main(){
	int n;
	cin>>n;
	ll sum=0;
	loop(i, 1, n+1){
		loop(j, 1, n+1){
			loop(k, 1, n+1){
				int g=k;
				g=gcd(g, j);
				g=gcd(g, i);
				sum+=g;
			}
		}
	}
	cout<<sum<<endl;
	return 0;
}