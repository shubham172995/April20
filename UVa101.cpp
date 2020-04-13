#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    getchar();
    vector<stack<int> > b(n);
    vector<int> a(n);
    for(int i=0;i<n;i++){
        b[i].push(i);
        a[i]=i;
    }
    while(1){
        string str;
        getline(cin, str);
        if(str=="quit")
            break;
        string temp=str.substr(0, 4);
        if(temp=="move"){
            int idx=0;
            for(int i=5;i<str.length();i++)
                if(str[i]==' '){
                    idx=i+1;
                    break;
                }
            temp=str.substr(idx, 4);
            if(temp=="onto"){
                int from=0, to=0;
                from=str[5]-'0';
                if(str[6]!=' ')
                    from=from*10+(str[6]-'0');
                if(str[str.length()-2]!=' ')
                    to=str[str.length()-2]-'0';
                to=to*10+(str[str.length()-1]-'0');
                //cout<<"Hey "<<b[a[from]].top()<<" "<<a[to]<<endl;
                if(from==to||b[a[from]].top()==b[a[to]].top()){
                    continue;
                }
                while(b[a[from]].top()!=from){
                    a[b[a[from]].top()]=b[a[from]].top();
                    b[b[a[from]].top()].push(b[a[from]].top());
                    b[a[from]].pop();
                }
                while(b[a[to]].top()!=to){
                    a[b[a[to]].top()]=b[a[to]].top();
                    b[b[a[to]].top()].push(b[a[to]].top());
                    b[a[to]].pop();
                }
                b[a[from]].pop();
                b[a[to]].push(from);
                a[from]=a[to];
            }
            else if(temp=="over"){
                int from=0, to=0;
                from=str[5]-'0';
                if(str[6]!=' ')
                    from=from*10+(str[6]-'0');
                if(str[str.length()-2]!=' ')
                    to=str[str.length()-2]-'0';
                to=to*10+(str[str.length()-1]-'0');
                if(from==to||b[a[from]].top()==b[a[to]].top()){
                    //cout<<"OKAY "<<from<<" "<<to<<endl;
                    continue;
                }
                while(b[a[from]].top()!=from){
                    a[b[a[from]].top()]=b[a[from]].top();
                    b[b[a[from]].top()].push(b[a[from]].top());
                    b[a[from]].pop();
                }
                b[a[from]].pop();
                b[a[to]].push(from);
                a[from]=a[to];
            }
        }
        else if(temp=="pile"){
            int idx=0;
            for(int i=5;i<str.length();i++)
                if(str[i]==' '){
                    idx=i+1;
                    break;
                }
            temp=str.substr(idx, 4);
            if(temp=="onto"){
                int from=0, to=0;
                from=str[5]-'0';
                if(str[6]!=' ')
                    from=from*10+(str[6]-'0');
                if(str[str.length()-2]!=' ')
                    to=str[str.length()-2]-'0';
                to=to*10+(str[str.length()-1]-'0');
                if(from==to||b[a[from]].top()==b[a[to]].top())
                    continue;
                stack<int> extra;
                /*if(from==13&&to==6)
                    cout<<"Hey "<<a[from]<<" "<<a[to]<<" "<<b[a[from]].top()<<" "<<b[a[to]].top()<<endl;*/
                while(b[a[from]].top()!=from){
                    extra.push(b[a[from]].top());
                    b[a[from]].pop();
                }
                extra.push(b[a[from]].top());
                b[a[from]].pop();
                while(b[a[to]].top()!=to){
                    a[b[a[to]].top()]=b[a[to]].top();
                    b[b[a[to]].top()].push(b[a[to]].top());
                    b[a[to]].pop();
                }
                while(extra.size()){
                    b[a[to]].push(extra.top());
                    a[extra.top()]=a[to];
                    extra.pop();
                }
                a[from]=a[to];
            }
            else if(temp=="over"){
                int from=0, to=0;
                from=str[5]-'0';
                if(str[6]!=' ')
                    from=from*10+(str[6]-'0');
                if(str[str.length()-2]!=' ')
                    to=str[str.length()-2]-'0';
                to=to*10+(str[str.length()-1]-'0');
                if(from==to||b[a[from]].top()==b[a[to]].top())
                    continue;
                stack<int> extra;
                while(b[a[from]].top()!=from){
                    extra.push(b[a[from]].top());
                    b[a[from]].pop();
                }
                extra.push(b[a[from]].top());
                b[a[from]].pop();
                while(extra.size()){
                    b[a[to]].push(extra.top());
                    a[extra.top()]=a[to];
                    extra.pop();
                }
                a[from]=a[to];
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<i<<":";
        stack<int> extra;
        while(b[i].size()){
            //cout<<" "<<b[i].top();
            extra.push(b[i].top());
            b[i].pop();
        }
        while(extra.size()){
            cout<<" "<<extra.top();
            extra.pop();
        }
        cout<<endl;
    }
    return 0;
}