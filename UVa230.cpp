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
	map<string, int> borrowed, returned;
	while(1){
		string str;
		getline(cin, str);
		if(str=="END")
			break;
		if(str[0]=='B'){
			string name=str.substr(7, str.length()-7);
			borrowed[name]=1;
		}
		else if(str[0]=='R'){
			string name=str.substr(7, str.length()-7);
			returned[name]=1;
			//cout<<endl<<shelf[shelf.size()-1].first<<" "<<shelf[shelf.size()-1].second;
		}
		else if(str=="SHELVE"){
			string last="";
			loop(i, 0, books.size()){
				if(!borrowed[books[i].second])
					last=books[i].second;
				else if(returned[books[i].second]){
					if(!last.length())
						cout<<"Put "<<books[i].second<<" first\n";
					else cout<<"Put "<<books[i].second<<" after "<<last<<endl;
					borrowed[books[i].second]=0;
					last=books[i].second;
				}
			}
			cout<<"END\n";
			returned.clear();
		}
	}
	return 0;
}