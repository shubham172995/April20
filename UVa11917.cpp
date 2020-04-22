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
	loop(k, 1, t+1){
		int n;
		scanf("%d", &n);
		map<string, int> m;
		loop(i, 0, n){
			getchar();
			string temp;
			int days;
			cin>>temp>>days;
			m[temp]=days;
		}
		int d;
		scanf("%d", &d);
		getchar();
		string subject;
		cin>>subject;
		cout<<"Case "<<k<<": ";
		if(m[subject]){
			if(m[subject]<=d)
				cout<<"Yesss\n";
			else if(m[subject]<=d+5)
				cout<<"Late\n";
			else cout<<"Do your own homework!\n";
		}
		else cout<<"Do your own homework!\n";
	}
	return 0;
}