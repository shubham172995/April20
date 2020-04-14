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
		int n, a, b;
		scanf("%d %d %d", &n, &a, &b);
		string ans="";
		loop(i, 0, n){
			ans+=('a'+i%b);
		}
		cout<<ans<<endl;
	}
	return 0;
}