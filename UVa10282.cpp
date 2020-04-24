#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lloop(i, a, b) for(ll i=a;i<(ll)b; i++)
#define loop(i, a, b) for(int i=a;i<b;i++)
#define pool(i, a, b) for(int i=a;i>b;i--)
#define pooll(i, a, b) for(ll i=a;i>b;i--)
#define pb push_back

int main(){
	string s1;
	map<string, string> m;
	while(getline(cin, s1)&&s1.length()){
		string a, b;
		istringstream is(s1);
		is>>a;
		is>>b;
		m[b]=a;
	}
	//cout<<s1<<endl;
	while(cin>>s1){
		if(m.find(s1)!=m.end())
			cout<<m[s1]<<endl;
		else cout<<"eh\n";
	}
	return 0;
}