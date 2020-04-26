#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lloop(i, a, b) for(ll i=a;i<(ll)b; i++)
#define loop(i, a, b) for(int i=a;i<b;i++)
#define pool(i, a, b) for(int i=a;i>b;i--)
#define pooll(i, a, b) for(ll i=a;i>b;i--)
#define pb push_back

vector<vector<int> > nodes(200005);
vector<int> parents(200005), ind;
vector<bool> industry(200005), visited(200005);
int industries;

void solve1(int parent, int n, int k, int anc){
	if(visited[parent])
		return;
	visited[parent]=1;
	parents[parent]=anc;
	//cout<<"Hey "<<parent<<endl;
	if(industries==k)
		return;
	if(nodes[parent].size()==1){
		++industries;
		industry[parent]=1;
		ind.push_back()
		return;
	}
	loop(i, 0, nodes[parent].size()){
		solve1(nodes[parent][i], n, k, parent);
	}
}

/*void bfs(int s, int k){
	cout<<s<<endl;
	queue<int> q;
	q.push(s);
	visited[s]=1;
	bool flag=false;
	while(q.size()){
		int v=q.front();
		q.pop();
		if(flag)
			break;
		loop(i, 0, nodes[v].size()){
			cout<<"Hey "<<nodes[v][i]<<endl;
			if(!visited[nodes[v][i]]){
				if(industries==k){
					flag=true;
					break;
				}
				cout<<v<<" "<<nodes[v][i]<<endl;
				q.push(nodes[v][i]);
				--industries;
				industry[nodes[v][i]]=0;
				visited[nodes[v][i]]=1;
			}
		}
	}
}*/

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	loop(i, 0, n-1){
		int a, b;
		scanf("%d %d", &a, &b);
		nodes[a].pb(b);
		nodes[b].pb(a);
	}
	solve1(1, n, k, -1);
	/*loop(i, 0, n){
		loop(j, 0, nodes[i].size()){
			cout<<"Parent = "<<i<<" child = "<<nodes[i][j]<<" Industry = "<<industry[nodes[i][j]]<<endl;
		}
	}*/
	/*loop(i, 1, n)
		visited[i]=0;
	if(industries<k){
		loop(i, 2, n)
			industry[i]=1;
		industries=n-1;
		bfs(1, k);
		cout<<industries<<endl;
	}*/
	queue<int> q;
	while(industries!=k){
		loop(i, 0, n){

		}
	}
	return 0;
}