#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lloop(i, a, b) for(ll i=a;i<(ll)b; i++)
#define loop(i, a, b) for(int i=a;i<b;i++)

int main(){
	while(1){
		string str;
		cin>>str;
		if(str=="#")
			break;
		string s1=str;
		next_permutation(str.begin(), str.end());
		if(str.compare(s1)<=0)
			cout<<"No Successor\n";
		else cout<<str<<endl;
	}
	return 0;
}