#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lloop(i, a, b) for(ll i=a;i<(ll)b; i++)
#define loop(i, a, b) for(int i=a;i<b;i++)
#define pool(i, a, b) for(int i=a;i>b;i--)
#define pooll(i, a, b) for(ll i=a;i>b;i--)
#define pb push_back

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int b, sg, sb;
		cin>>b>>sg>>sb;
		multiset<int> blue, green;
		loop(i, 0, sg){
			int temp;
			cin>>temp;
			green.insert(temp);
		}
		loop(i, 0, sb){
			int temp;
			cin>>temp;
			blue.insert(temp);
		}
		while(blue.size()&&green.size()){
			int m=min(b, (int)blue.size());
			m=min(m, (int)green.size());
			vector<int> gwins(m), diff(m);
			loop(i, 0, m){
				set<int>::iterator ib, ig;
				ib=blue.end();
				--ib;
				ig=green.end();
				--ig;
				diff[i]=abs(*ib-*ig);
				if(*ib==*ig){
					gwins[i]=0;
				}
				else if(*ig>*ib)
					gwins[i]=1;
				else gwins[i]=-1;
				green.erase(ig);
				blue.erase(ib);
			}
			loop(i, 0, m){
				if(gwins[i]==0)
					continue;
				else if(gwins[i]==-1)
					blue.insert(diff[i]);
				else green.insert(diff[i]);
			}
		}
		if(green.size()==0&&blue.size()==0){
			cout<<"green and blue died\n";
		}
		else if (blue.size() == 0){
           printf("green wins\n");
           multiset<int>::reverse_iterator it;
           for (it = green.rbegin(); it != green.rend(); it++)
               printf("%d\n",*it);
        } else {
           printf("blue wins\n");
           multiset<int>::reverse_iterator it;
           for (it = blue.rbegin(); it != blue.rend(); it++)
               printf("%d\n",*it);
        } 
		if(t)
			cout<<endl;
	}
	return 0;
}