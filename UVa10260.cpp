#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lloop(i, a, b) for(ll i=a;i<(ll)b; i++)
#define loop(i, a, b) for(int i=a;i<b;i++)

int main(){
	string str;
	map<char, char> m;
	m['B']=m['F']=m['P']=m['V']='1';
	m['C']=m['G']=m['J']=m['K']=m['Q']=m['S']=m['X']=m['Z']='2';
	m['D']=m['T']='3';
	m['L']='4';
	m['M']=m['N']='5';
	m['R']='6';
	m['A']=m['E']=m['I']=m['O']=m['U']=m['H']=m['W']=m['Y']='0';
	while(cin>>str){
		string ans="";
		loop(i, 0, str.length()){
			if(m[str[i]]=='0')
				continue;
			if(i>0&&m[str[i]]==m[str[i-1]])
				continue;
			ans+=m[str[i]];
		}
		cout<<ans<<endl;
	}
	return 0;
}