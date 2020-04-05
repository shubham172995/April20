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
		vector<pair<int, int> > p(n), q(n);
		loop(i, 0, n){
			int l, r;
			pair<int, int> pe, qe;
			cin>>l>>r;
			pe.first=l;
			pe.second=i;
			qe.first=r;
			qe.second=i;
			p[i]=pe;
			q[i]=qe;
			d[l]+=1;
			d[r]-=1;
		}
		cout<<"Case #"<<x<<": ";
		a[0]=d[0];
		loop(i, 1, 1441){
			a[i]=a[i-1]+d[i];
		}
		bool flag=true;
		sort(p.begin(), p.end());
		sort(q.begin(), q.end());
		vector<char> ans(n);
		int i=0, j=0, ca=0, count=0, ja=0;
		while(1){
			//cout<<"HEY\n";
			if(i==n&&j==n)
				break;
			//cout<<p[i].first<<" "<<q[j].first<<" ";
			if(i<n && p[i].first<q[j].first){
				++count;
				if(count>2){
					flag=false;
					break;
				}
				if(ca==0){
					ca=1;
					ans[p[i].second]='C';
				}
				else if(ja==0){
					ja=1;
					ans[p[i].second]='J';
				}
				++i;
				//cout<<ans[p[i].second]<<" ";
			}
			else{
				//cout<<" Hey "<<ans[q[j].second]<<" ";
				if(ans[q[j].second]=='J')
					--ja;
				else --ca;
				--count;
				++j;
			}
		}
		if(!flag)
			cout<<"IMPOSSIBLE";
		else loop(i, 0, n)
			cout<<ans[i];
		cout<<endl;
	}
	return 0;
}