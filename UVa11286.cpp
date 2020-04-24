#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lloop(i, a, b) for(ll i=a;i<(ll)b; i++)
#define loop(i, a, b) for(int i=a;i<b;i++)
#define pool(i, a, b) for(int i=a;i>b;i--)
#define pooll(i, a, b) for(ll i=a;i>b;i--)
#define pb push_back

int main(){
	while(1){
		int n;
		scanf("%d", &n);
		if(n==0)
			break;
		int ans=0, count=0;
		map<string, int> m;
		vector<string> temp(n);
		loop(i, 0, n){
			string str="";
			vector<int> a(5);
			loop(j, 0, 5)
				cin>>a[j];
			sort(a.begin(), a.end());
			loop(j, 0, 5){
				str+=to_string(a[j]);
			}
			temp[i]=str;
			++m[str];
			count=count>m[str]?count:m[str];
		}
		loop(i, 0, n){
			if(m[temp[i]]==count)
				++ans;
		}
		cout<<ans<<endl;
	}
	return 0;
}