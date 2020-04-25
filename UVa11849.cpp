#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lloop(i, a, b) for(ll i=a;i<(ll)b; i++)
#define loop(i, a, b) for(int i=a;i<b;i++)
#define pool(i, a, b) for(int i=a;i>b;i--)
#define pooll(i, a, b) for(ll i=a;i>b;i--)
#define pb push_back

int main(){
	int n, m;
	while(1){
		cin>>n>>m;
		if(n==0&&m==0)
			break;
		set<int> s;
		int count=0;
		loop(i, 0, n){
			int temp;
			cin>>temp;
			s.insert(temp);
		}
		loop(i, 0, m){
			int temp;
			cin>>temp;
			if(s.insert(temp).second)
				continue;
			else ++count;
		}
		cout<<count<<endl;
	}
	return 0;
}