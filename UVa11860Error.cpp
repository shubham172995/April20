#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lloop(i, a, b) for(ll i=a;i<(ll)b; i++)
#define loop(i, a, b) for(int i=a;i<b;i++)
#define pool(i, a, b) for(int i=a;i>b;i--)
#define pooll(i, a, b) for(ll i=a;i>b;i--)
#define pb push_back

/*class mycomparator{
public:
	int operator()(const pair<int, string>& a, const pair<int, string>& b){
		return a.first>b.first;
	}
};*/

int main(){
	int t;
	scanf("%d", &t);
	getchar();
	loop(k, 1, t+1){
		string s;
		while(1){
			string a;
			getline(cin, a);
			if(a=="END")
				break;
			s+=a+' ';
		}
		istringstream is(s);
		map<string, bool> m;
		string temp="";
		int words=0;
		vector<string> para;
		while(is>>temp){
			string word="";
			bool flag=false;
			loop(i, 0, temp.length()){
				if(!(temp[i]>='a'&&temp[i]<='z')){
					flag=true;
				}
				else word+=temp[i];
				if(flag&&word.length()){
					if(m[word]){
						para.pb(word);
					}
					else{
						m[word]=1;
						para.pb(word);
						++words;
					}
					word="";
				}
			}
			if(word.length()){
				bool check=false;
				loop(j, 0, word.length()){
					if(!(word[j]>='a'&&word[j]<='z')){
						check=true;
						break;
					}
				}
				if(check)
					continue;
				para.pb(word);
				if(m[word])
					continue;
				m[word]=1;
				++words;
			}
		}
		queue<pair<string, int> > q;
		int st=0, en=999999, count=0, cini=0;
		map<string, int> match;
		loop(i, 0, para.size()){
			if(match[para[i]]==0)
				++count;
			++match[para[i]];
			q.push(make_pair(para[i], i));
			while(match[q.front().first]>1){
				match[q.front().first]-=1;
				q.pop();
				cini=q.front().second;
			}
			if(count==words){
				if(i-cini<en-st)st=cini, en=i;
			}
		}
		cout<<"Document "<<k<<": "<<st+1<<" "<<en+1<<endl;
	}
	return 0;
}