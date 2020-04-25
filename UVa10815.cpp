#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lloop(i, a, b) for(ll i=a;i<(ll)b; i++)
#define loop(i, a, b) for(int i=a;i<b;i++)
#define pool(i, a, b) for(int i=a;i>b;i--)
#define pooll(i, a, b) for(ll i=a;i>b;i--)
#define pb push_back

int main(){
	string str;
	set<string> s;
	while(getline(cin, str)){
		/*if(str=="END")
			break;*/
		int p=0, l=str.length();
		loop(i, 0, l){
			if(isalpha(str[i]))
				str[i]=tolower(str[i]);
			else str[i]=' ';
		}
		stringstream ss(str);
		string temp="";
		while(ss>>temp)
			s.insert(temp);
	}
	for(set<string>::iterator it=s.begin(); it!=s.end(); ++it)
		cout<<*it<<endl;
	return 0;
}