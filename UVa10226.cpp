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
	getchar();
	getchar();
	while(t--){
		map<string, int> m;
		vector<string> trees;
		string str;
		int counter=0;
		while(getline(cin, str)&&str!=""){
			++counter;
			if(m[str])
				++m[str];
			else{
				trees.pb(str);
				m[str]=1;
			}
		}
		sort(trees.begin(), trees.end());
		loop(i, 0, trees.size()){
			//cout<<trees[i]<<" "<<m[trees[i]]<<endl;
			float per=100;
			per*=(m[trees[i]]+0.0000)/counter;
			cout<<trees[i];
			printf(" %.4f\n", per);
		}
		if(t){
			cout<<endl;
		}
	}
	return 0;
}