#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lloop(i, a, b) for(ll i=a;i<(ll)b; i++)
#define loop(i, a, b) for(int i=a;i<b;i++)
#define pool(i, a, b) for(int i=a;i>b;i--)
#define pooll(i, a, b) for(ll i=a;i>b;i--)
#define pb push_back

int main(){
	while(1){
		multiset<int> m;
		int n;
		scanf("%d", &n);
		if(n==0)
			break;
		ll ans=0;
		loop(i, 0, n){
			int k;
			cin>>k;
			loop(i, 0, k){
				int temp;
				cin>>temp;
				m.insert(temp);
			}
			multiset<int>::iterator it=m.end();
			multiset<int>::iterator it1=m.begin();
			--it;
			ans+=*it-*it1;
			m.erase(it);
			m.erase(it1);
			//cout<<"HEY "<<*(m.begin())<<" "<<*it<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}