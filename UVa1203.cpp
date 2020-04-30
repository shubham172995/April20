#include<bits/stdc++.h>
using namespace std;

struct element{
    int inc, fin, id;
};

struct comp{
    bool operator()(element& a, element& b){
        if(a.fin!=b.fin){
            return a.fin>b.fin;
        }
        return a.id>b.id;
    }
};

int main(){
    element temp;
    priority_queue<element, vector<element>, comp> q;
    while(1){
        string str;
        cin>>str;
        if(str=="#")
            break;
        int a, b;
        cin>>a>>b;
        getchar();
        temp.id=a;
        temp.fin=temp.inc=b;
        q.push(temp);
    }
    int k;
    cin>>k;
    while(k--){
        cout<<q.top().id<<endl;
        temp=q.top();
        q.pop();
        temp.fin+=temp.inc;
        q.push(temp);
    }
    return 0;
}