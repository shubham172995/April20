#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lloop(i, a, b) for(ll i=a;i<(ll)b; i++)
#define loop(i, a, b) for(int i=a;i<b;i++)
#define pool(i, a, b) for(int i=a;i>b;i--)
#define pooll(i, a, b) for(ll i=a;i>b;i--)
#define pb push_back

bool check[3005];

int main(){
	int n;
	cin>>n;
	loop(i, 0, n){
		int temp;
		cin>>temp;
		check[temp]=1;
	}
	loop(i, 1, 3002){
		if(check[i]==0){
			cout<<i<<endl;
			break;
		}
	}
	return 0;
}