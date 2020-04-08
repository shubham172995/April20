#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lloop(i, a, b) for(ll i=a;i<(ll)b; i++)
#define loop(i, a, b) for(int i=a;i<b;i++)
#define pooll(i, a, b) for(ll i=a;i>(ll)b; i--)
#define pool(i, a, b) for(int i=a;i>b;i--)

int main(){
	int n;
	while(1){
		cin>>n;
		if(!n)
			break;
		vector<int> a(n);
		loop(i, 0, n){
			cin>>a[i];
		}
		sort(a.begin(), a.end());
		bool flag=false;
		loop(i, 0, n-1){
			if(a[i+1]-a[i]>200){
				flag=true;
				break;
			}
		}
		if(flag){
			cout<<"IMPOSSIBLE\n";
			continue;
		}
		int fuel=0;
		if(a[a.size()-1]>=1222){
			fuel=200-(1422-a[a.size()-1]);
		}
		else{
			cout<<"IMPOSSIBLE\n";
			continue;
		}
		//cout<<fuel<<endl;
		if(1422-a[a.size()-1]<=fuel){
			cout<<"POSSIBLE\n";
		}
		else cout<<"IMPOSSIBLE\n";
		/*pool(i, a.size()-1, -1){
			if(fuel>=location-a[i]){
				fuel=200;
				location=a[i];
			}
		}*/
	}
	return 0;
}