#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lloop(i, a, b) for(ll i=a;i<(ll)b; i++)
#define loop(i, a, b) for(int i=a;i<b;i++)
#define pool(i, a, b) for(int i=a;i>b;i--)
#define pooll(i, a, b) for(ll i=a;i>b;i--)
#define pb push_back

struct stats{
	int points, wins, goaldiff, goalsscored, gamesplayed, goalsagainst, losses;
	string name;
};

struct comp{
	bool operator()(const struct stats& n1, struct stats& n2){
		if(n1.points>n2.points)
			return true;
		else if(n1.points==n2.points){
			if(n1.wins>n2.wins)
				return true;
			else if(n1.wins==n2.wins){
				if(n1.goaldiff>n2.goaldiff)
					return true;
				else if(n1.goaldiff==n2.goaldiff){
					if(n1.goalsscored>n2.goalsscored)
						return true;
					else if(n1.goalsscored==n2.goalsscored){
						if(n1.gamesplayed<n2.gamesplayed)
							return true;
						else if(n1.gamesplayed==n2.gamesplayed){
							string a, b;
							a=n1.name;
							b=n2.name;
							loop(i, 0, a.length())
								a[i]=tolower(a[i]);
							loop(i, 0, b.length())
								b[i]=tolower(b[i]);
							if(a<b)
								return true;
						}
					}
				}
			}
		}
		return false;
	}
};

int main(){
	int n;
	scanf("%d", &n);
	getchar();
	while(n--){
		string tournament;
		getline(cin, tournament);
		int teams;
		cin>>teams;
		getchar();
		vector<string> teamnames(teams);
		map<string, int> m;
		loop(i, 0, teams){
			getline(cin, teamnames[i]);
			m[teamnames[i]]=i;
		}
		int g;
		cin>>g;
		getchar();
		vector<struct stats> decider(teams);
		loop(i, 0, teams){
			decider[i].points = decider[i].wins = decider[i].goaldiff = decider[i].losses = decider[i].goalsscored = decider[i].gamesplayed=decider[i].goalsagainst=0;
			decider[i].name=teamnames[i];
		}
		loop(i, 0, g){
			string temp, k, team1, team2, g1, g2;
			getline(cin, temp);
			int j, counter=0, goals1=0, goals2=0;
			for(j=0;j<temp.length();j++){
				if(temp[j]=='#'){
					++counter;
					if(counter==1){
						decider[m[k]].name=k;
						team1=k;
						k="";
					}
					else if(counter==2){
						decider[m[temp.substr(j+1, temp.length()-j)]].name=temp.substr(j+1, temp.length()-j);
						team2=temp.substr(j+1, temp.length()-j);
						g2=k;
					}
				}
				else if(temp[j]=='@'){
					g1=k;
					k="";
				}
				else k+=temp[j];
			}
			//cout<<g1<<" "<<g2<<endl;
			loop(j, 0, g1.length()){
				goals1=goals1*10+(g1[j]-'0');
			}
			loop(j, 0, g2.length()){
				goals2=goals2*10+(g2[j]-'0');
			}
			//cout<<team1<<" "<<team2<<" "<<m[team1]<<" "<<m[team2]<<" "<<goals1<<" "<<goals2<<endl;
			if(g1>g2){
				decider[m[team1]].wins=decider[m[team1]].wins+1;
				decider[m[team1]].points=decider[m[team1]].points+3;
				decider[m[team1]].goalsagainst=decider[m[team1]].goalsagainst+goals2;
				decider[m[team1]].goalsscored=decider[m[team1]].goalsscored+goals1;
				decider[m[team1]].goaldiff=decider[m[team1]].goalsscored-decider[m[team1]].goalsagainst;
				decider[m[team1]].gamesplayed=decider[m[team1]].gamesplayed+1;
				decider[m[team2]].losses=decider[m[team2]].losses+1;
				decider[m[team2]].points=decider[m[team2]].points+0;
				decider[m[team2]].goalsscored=decider[m[team2]].goalsscored+goals2;
				decider[m[team2]].goalsagainst=decider[m[team2]].goalsagainst+goals1;
				decider[m[team2]].goaldiff=decider[m[team2]].goalsscored-decider[m[team2]].goalsagainst;
				decider[m[team2]].gamesplayed=decider[m[team2]].gamesplayed+1;
			}
			else if(g2>g1){
				decider[m[team2]].wins=decider[m[team2]].wins+1;
				decider[m[team2]].points=decider[m[team2]].points+3;
				decider[m[team2]].goalsscored=decider[m[team2]].goalsscored+goals2;
				decider[m[team2]].goalsagainst=decider[m[team2]].goalsagainst+goals1;
				decider[m[team2]].goaldiff=decider[m[team2]].goalsscored-decider[m[team2]].goalsagainst;
				decider[m[team2]].gamesplayed=decider[m[team2]].gamesplayed+1;
				decider[m[team1]].losses=decider[m[team1]].losses+1;
				decider[m[team1]].points=decider[m[team1]].points+0;
				decider[m[team1]].goalsscored=decider[m[team1]].goalsscored+goals1;
				decider[m[team1]].goalsagainst=decider[m[team1]].goalsagainst+goals2;
				decider[m[team1]].goaldiff=decider[m[team1]].goalsscored-decider[m[team1]].goalsagainst;
				decider[m[team1]].gamesplayed=decider[m[team1]].gamesplayed+1;
			}
			else{
				decider[m[team1]].wins=decider[m[team1]].wins+0;
				decider[m[team1]].points=decider[m[team1]].points+1;
				decider[m[team1]].goalsscored=decider[m[team1]].goalsscored+goals1;
				decider[m[team1]].goalsagainst=decider[m[team1]].goalsagainst+goals2;
				decider[m[team1]].goaldiff=decider[m[team1]].goalsscored-decider[m[team1]].goalsagainst;
				decider[m[team1]].gamesplayed=decider[m[team1]].gamesplayed+1;
				decider[m[team2]].wins=decider[m[team2]].wins+0;
				decider[m[team2]].points=decider[m[team2]].points+1;
				decider[m[team2]].goalsscored=decider[m[team2]].goalsscored+goals2;
				decider[m[team2]].goalsagainst=decider[m[team2]].goalsagainst+goals1;
				decider[m[team2]].goaldiff=decider[m[team2]].goalsscored-decider[m[team2]].goalsagainst;
				decider[m[team2]].gamesplayed=decider[m[team2]].gamesplayed+1;
			}
		}
		/*loop(i, 0, teams){
			cout<<teamnames[i]<<" "<<decider[m[teamnames[i]]].wins<<" "<<decider[m[teamnames[i]]].points<<" "<<decider[m[teamnames[i]]].goaldiff<<" "<<decider[m[teamnames[i]]].goalsscored<<" "<<decider[m[teamnames[i]]].gamesplayed<<endl;
		}*/
		sort(decider.begin(), decider.end(), comp());
		cout<<tournament<<endl;
		loop(i, 0, decider.size()){
			int draws=decider[i].gamesplayed-(decider[i].wins+decider[i].losses);
			cout<<i+1<<") "<<decider[i].name<<" "<<decider[i].points<<"p, "<<decider[i].gamesplayed<<"g ("<<decider[i].wins<<"-";
			cout<<draws<<"-"<<decider[i].losses<<"), "<<decider[i].goaldiff<<"gd ("<<decider[i].goalsscored<<"-"<<decider[i].goalsagainst<<")\n";
		}
		if(n)
			cout<<endl;
	}
	return 0;
}