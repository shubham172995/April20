#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lloop(i, a, b) for(ll i=a;i<(ll)b; i++)
#define loop(i, a, b) for(int i=a;i<b;i++)

int main(){
	int n;
	cin>>n;
	string s="";
	getchar();
	cin>>s;
	ll ans=0;
	vector<int> r, g, b;
	loop(i, 0, n){
		if(s[i]=='R')
			r.push_back(i);
		else if(s[i]=='G')
			g.push_back(i);
		else if(s[i]=='B') b.push_back(i);
	}
	/*loop(i, 0, r.size())
		cout<<r[i]<<" ";
	cout<<endl;
	loop(i, 0, g.size())
		cout<<g[i]<<" ";
	cout<<endl;
	loop(i, 0, b.size())
		cout<<b[i]<<" ";
	cout<<endl;
	loop(i, 0, n){
		loop(j, i+1, n){
			if(s[j]==s[i])
				continue;
			loop(k, j+1, n){
				if(s[k]==s[j]||s[k]==s[i])
					continue;
				if(k-j==j-i)
					continue;
				++sum;
			}
		}
	}*/
	loop(i, 0, n){
		if(s[i]=='R'){
			loop(j, 0, g.size()){
				if(g[j]<i)
					continue;
				loop(k, 0, b.size()){
					if(b[k]<g[j])
						continue;
					if(g[j]-i==b[k]-g[j])
						continue;
					if(g[j]-i>b[k]-g[j])
						++ans;
					else{
						ans+=b.size()-k;
						break;
					}
				}
			}
			loop(j, 0, b.size()){
				if(b[j]<i)
					continue;
				loop(k, 0, g.size()){
					if(g[k]<b[j])
						continue;
					if(b[j]-i==g[k]-b[j])
						continue;
					if(b[j]-i>g[k]-b[j])
						++ans;
					else{
						ans+=g.size()-k;
						break;
					}
					//cout<<i<<" "<<b[j]<<" "<<g[k]<<endl;
				}
			}
		}
		else if(s[i]=='G'){
			loop(j, 0, r.size()){
				if(r[j]<i)
					continue;
				loop(k, 0, b.size()){
					if(b[k]<r[j])
						continue;
					if(r[j]-i==b[k]-r[j])
						continue;
					if(r[j]-i>b[k]-r[j])
						++ans;
					else{
						ans+=b.size()-k;
						break;
					}
				}
			}
			loop(j, 0, b.size()){
				if(b[j]<i)
					continue;
				loop(k, 0, r.size()){
					if(r[k]<b[j])
						continue;
					if(b[j]-i==r[k]-b[j])
						continue;
					if(b[j]-i>r[k]-b[j])
						++ans;
					else{
						ans+=r.size()-k;
						break;
					}
				}
			}
		}
		else if(s[i]=='B'){
			loop(j, 0, r.size()){
				if(r[j]<i)
					continue;
				loop(k, 0, g.size()){
					if(g[k]<r[j])
						continue;
					else if(r[j]-i==g[k]-r[j])
						continue;
					if(r[j]-i>g[k]-r[j])
						++ans;
					else{
						ans+=g.size()-k;
						break;
					}
				}
			}
			loop(j, 0, g.size()){
				if(g[j]<i)
					continue;
				loop(k, 0, r.size()){
					if(r[k]<g[j])
						continue;
					else if(g[j]-i==r[k]-g[j])
						continue;
					if(g[j]-i>r[k]-g[j])
						++ans;
					else{
						ans+=r.size()-k;
						break;
					}
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}