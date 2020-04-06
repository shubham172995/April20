/*
PROBLEM WITH THIS CODE IS THAT BASED ON CONDITIONS, I HAVE FIXED POSITIONS ON THE RACK FOR THE BOOKS. THEY DIDN'T MENTION THAT
THE POSITIONS WERE FIXED.
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lloop(i, a, b) for(ll i=a;i<(ll)b; i++)
#define loop(i, a, b) for(int i=a;i<b;i++)

int main(){	
	vector<pair<string, string> > books;
	while(1){
		string str;
		getline(cin, str);
		if(str=="END")
			break;
		pair<string, string> temp;
		int i=1;
		while(str[i]!='"'){
			++i;
		}
		temp.second=str.substr(0, i+1);
		i+=5;
		temp.first=str.substr(i, str.length()-i);
		books.push_back(temp);
	}
	sort(books.begin(), books.end());
	map<string, int> m;
	map<int, string> n;
	loop(i, 0, books.size()){
		m[books[i].second]=i;
		n[i]=books[i].second;
	}
	vector<pair<int, string> > shelf;
	vector<bool> borrowed(books.size());
	while(1){
		string str;
		getline(cin, str);
		if(str=="END")
			break;
		if(str[0]=='B'){
			string name=str.substr(7, str.length()-7);
			borrowed[m[name]]=1;
		}
		else if(str[0]=='R'){
			string name=str.substr(7, str.length()-7);
			pair<int, string> p;
			p.first=m[name];
			p.second=name;
			shelf.push_back(p);
			//cout<<endl<<shelf[shelf.size()-1].first<<" "<<shelf[shelf.size()-1].second;
		}
		else if(str=="SHELVE"){
			sort(shelf.begin(), shelf.end());
			//cout<<shelf.size()<<endl;
			loop(i, 0, shelf.size()){
				if(shelf[i].first==0||borrowed[shelf[i].first-1]){
					cout<<"Put "<<shelf[i].second<<" first\n";
					borrowed[shelf[i].first]=0;
				}
				else{
					cout<<"Put "<<shelf[i].second<<" after "<<n[shelf[i].first-1]<<endl;
					borrowed[shelf[i].first]=0;
				}
			}
			cout<<"END\n";
			shelf.clear();
		}
	}
	return 0;
}