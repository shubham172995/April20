#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lloop(i, a, b) for(ll i=a;i<(ll)b; i++)
#define loop(i, a, b) for(int i=a;i<b;i++)
#define pool(i, a, b) for(int i=a;i>b;i--)
#define pooll(i, a, b) for(ll i=a;i>b;i--)
#define pb push_back

#define maxn 200005
vector<vector<ll> > graph(maxn);
vector<ll> depth(maxn), happ(maxn), size(maxn);
ll n, k;

struct comp{
	bool operator()(const ll& a, const ll& b){
		return a>b;
	}
};

ll dfs(ll u, ll p){
	//cout<<u<<" "<<p<<endl;
	depth[u]=depth[p]+1;
	size[u]=1;
	loop(i, 0, graph[u].size()){
		if(graph[u][i]==p)
			continue;
		size[u]+=dfs(graph[u][i], u);
	}
	happ[u]=size[u]-depth[u];
	return size[u];
}

int main(){
	cin>>n>>k;
	loop(i, 0, n-1){
		ll a, b;
		cin>>a>>b;
		graph[a].pb(b);
		graph[b].pb(a);
	}
	//cout<<n<<" "<<k<<endl;
	ll ans=0;
	dfs(1, 0);
	sort(happ.begin()+1, happ.begin()+n+1, comp());
	/*loop(i, 1, n+1)
		cout<<happ[i]<<endl;*/
	loop(i, 1, n-k+1){
		ans+=happ[i];
	}
	cout<<ans<<endl;
	return 0;
}