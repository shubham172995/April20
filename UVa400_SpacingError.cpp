#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lloop(i, a, b) for(ll i=a;i<(ll)b; i++)
#define loop(i, a, b) for(int i=a;i<b;i++)
#define pool(i, a, b) for(int i=a;i>b;i--)
#define pooll(i, a, b) for(ll i=a;i>b;i--)
#define pb push_back

int main(){
	int n;
	while(cin>>n){
		getchar();
		int max=0;
		vector<string> names(n);
		loop(i, 0, n){
			cin>>names[i];
			max=max>names[i].length()?max:names[i].length();
		}
		loop(i, 0, 60)
			cout<<"-";
		cout<<endl;
		int cols=60/(max+2);
		if(60%(max+2)>=max)
			++cols;
		int rows=n/cols;
		rows+=n%cols!=0;
		//cout<<rows<<" "<<cols<<endl;
		vector<vector<string> > table(rows);
		loop(i, 0, rows)
			table[i].resize(cols);
		//table[rows-1].resize(n%rows==0?cols:n%rows);
		//cout<<table[rows-1].size()<<endl;
		sort(names.begin(), names.end());
		int idx=0;
		bool flag=false;
		loop(j, 0, cols){
			loop(i, 0, rows){
				if(idx==n){
					flag=true;
					break;
				}
				table[i][j]=names[idx];
				++idx;
			}
			if(flag)
				break;
		}
		loop(i, 0, rows){
			loop(j, 0, cols){
				if(j<cols-1){
					//cout<<idx<<endl;
					cout<<table[i][j];
					loop(k, table[i][j].length(), max+2)
						cout<<" ";
				}
				else{
					cout<<table[i][j];
					loop(k, table[i][j].length(), max)
						cout<<" ";
				}
				++idx;
			}
			cout<<endl;
		}
	}
	return 0;
}