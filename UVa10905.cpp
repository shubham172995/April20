#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lloop(i, a, b) for(ll i=a;i<(ll)b; i++)
#define loop(i, a, b) for(int i=a;i<b;i++)
#define pool(i, a, b) for(int i=a;i>b;i--)
#define pooll(i, a, b) for(ll i=a;i>b;i--)
#define pb push_back

struct comp{
	bool operator()(const string& s1, const string& s2){
		return s1+s2>s2+s1;
	}
};

int main(){
	while(1){
		int n;
		cin>>n;
		if(n==0)
			break;
		getchar();
		vector<string> ans(n);
		loop(i, 0, n){
			cin>>ans[i];
		}
		sort(ans.begin(), ans.end(), comp());
		cout<<accumulate(ans.begin(), ans.end(), static_cast<string>(""))<<endl;
	}
	return 0;
}