#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lloop(i, a, b) for(ll i=a;i<(ll)b; i++)
#define loop(i, a, b) for(int i=a;i<b;i++)

int main(){
	int t;
	cin>>t;
	loop(x, 1, t+1){
		int n;
		cin>>n;
		vector<int> a(1441), d(1441);
		vector<pair<int, int> > ac(n);
		loop(i, 0, n){
			int l, r;
			pair<int, int> p;
			cin>>l>>r;
			p.first=l;
			p.second=r;
			ac[i]=p;
			d[l]+=1;
			d[r]-=1;
		}
		cout<<"Case #"<<x<<": ";
		a[0]=d[0];
		loop(i, 1, 1441){
			a[i]=a[i-1]+d[i];
		}
		bool flag=false;
		loop(i, 0, 1441){
			if(a[i]>2){
				cout<<"IMPOSSIBLE\n";
				flag=true;
				break;
			}
		}
		if(flag)
			continue;
		vector<char> ans(n);
		ans[0]='C';
		flag=false;
		loop(i, 1, n){
			loop(j, 0, i){
				if((ac[i].first>=ac[j].first&&ac[i].first<ac[j].second)||(ac[i].second>ac[j].first&&ac[i].second<=ac[j].second)){
					ans[i]=ans[j]=='C'?'J':'C';
					flag=true;
					break;
				}
			}
			if(flag){
				flag=false;
				continue;
			}
			ans[i]='C';
		}
		loop(i, 0, n)
			cout<<ans[i];
		cout<<endl;
	}
	return 0;
}