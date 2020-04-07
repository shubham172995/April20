#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lloop(i, a, b) for(ll i=a;i<(ll)b; i++)
#define loop(i, a, b) for(int i=a;i<b;i++)

int main(){
	int t;
	cin>>t;
	getchar();
	while(t--){
		getchar();
		string str, temp="";
		getline(cin, str);
		vector<int> p;
		loop(i, 0, str.length()){
			if(str[i]==' '){
				int k=0;
				loop(j, 0, temp.length()){
					k=k*10+(temp[j]-'0');
				}
				temp="";
				p.push_back(k);
			}
			else if(i==str.length()-1){
				temp+=str[i];
				int k=0;
				loop(j, 0, temp.length()){
					k=k*10+(temp[j]-'0');
				}
				temp="";
				p.push_back(k);
			}
			else{
				temp+=str[i];
			}
		}
		str="";
		getline(cin, str);
		//cout<<str<<endl;
		vector<string> q;
		loop(i, 0, str.length()){
			if(str[i]==' '){
				q.push_back(temp);
				temp="";
			}
			else if(i==str.length()-1){
				temp+=str[i];
				q.push_back(temp);
				temp="";
			}
			else{
				temp+=str[i];
			}
		}
		vector<string> ans(p.size());
		loop(i, 0, p.size()){
			ans[p[i]-1]=q[i];
		}
		loop(i, 0, ans.size())
			cout<<ans[i]<<endl;
		if(t)
			puts("");
	}
	return 0;
}