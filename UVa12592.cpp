#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lloop(i, a, b) for(ll i=a;i<(ll)b; i++)
#define loop(i, a, b) for(int i=a;i<b;i++)
#define pool(i, a, b) for(int i=a;i>b;i--)
#define pooll(i, a, b) for(ll i=a;i>b;i--)
#define pb push_back

int main(){
	int n;
	scanf("%d", &n);
	getchar();
	map<string, string> m;
	loop(i, 0, n){
		string a, b;
		getline(cin, a);
		getline(cin, b);
		m[a]=b;
	}
	int no;
	scanf("%d", &no);
	getchar();
	loop(i, 0, no){
		string a;
		getline(cin, a);
		cout<<m[a]<<endl;
	}
	return 0;
}