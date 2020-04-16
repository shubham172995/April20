#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lloop(i, a, b) for(ll i=a;i<(ll)b; i++)
#define loop(i, a, b) for(int i=a;i<b;i++)
#define pool(i, a, b) for(int i=a;i>b;i--)
#define pooll(i, a, b) for(ll i=a;i>b;i--)
#define pb push_back

int main(){
	int N;
	cin>>N;
	while(N--){
		int n, k;
		cin>>n>>k;
		int res=k^(k>>1);
		cout<<res<<endl;
	}
	return 0;
}