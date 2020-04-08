#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lloop(i, a, b) for(ll i=a;i<(ll)b; i++)
#define loop(i, a, b) for(int i=a;i<b;i++)

int main(){
	int n;
	cin>>n;
	while(n--){
		map<char, int> a;
		int k;
		cin>>k;
		loop(i, 0, k){
			char ch;
			int temp;
			cin>>ch>>temp;
			a[ch]=temp;
		}
		double ans=0;
		string str;
		int m;
		cin>>m;
		getchar();
		while(m--){
			getline(cin, str);
			loop(i, 0, str.length()){
				ans+=a[str[i]];
			}
		}
		printf("%.2lf", ans/100.00);
		cout<<"$\n";
	}
	return 0;
}