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
	scanf("%d %d", &n, &m);
	getchar();
	map<string, int> cost;
	loop(i, 0, n){
		string s;
		int temp;
		cin>>s>>temp;
		cost[s]=temp;
		getchar();
	}
	vector<string> line(m);
	loop(i, 0, m){
		string a="";
		while(1){
			getline(cin, a);
			if(a==".")
				break;
			line[i]+=a+' ';
		}
	}
	loop(i, 0, m){
		ll ans=0;
		istringstream is(line[i]);
		string word;
		while(is>>word){
			ans+=cost[word];
		}
		cout<<ans<<endl;
	}
	return 0;
}