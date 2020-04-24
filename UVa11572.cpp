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
		ll n;
		cin>>n;
		map<ll, int> m;
		int prev=0;
		ll count=0, ans=0;
		loop(i, 1, n+1){
			ll temp;
			cin>>temp;
			int pos=m[temp];
			if(pos!=0){
				prev=max(prev, pos);	//Remove the block from previous occurence of this element which has been repeated till present index. eg., 1 2 3 2 1. Here, when we get to 2nd 2, we remove the number of elements between 1st 2 and 2nd two.
				count=i-prev-1;
			}
			m[temp]=i;
			++count;
			ans=ans>count?ans:count;
		}
		cout<<ans<<endl;
	}
	return 0;
}